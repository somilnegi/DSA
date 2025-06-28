#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include "table.h"

using namespace std;

// Check if a given string is a valid hexadecimal number
bool isValidHex(const string& str) {
    return !str.empty() && str.find_first_not_of("0123456789abcdefABCDEF") == string::npos;
}

string removeExtraSpaces(const std::string& str) {
    istringstream iss(str);
    string word;
    ostringstream oss;

    bool firstWord = true;
    while (iss >> word) {
        if (!firstWord) {
            oss << " ";  // Add a single space before each word except the first
        }
        oss << word;
        firstWord = false;
    }

    return oss.str();
}

string cleanLabel(const string& label) {
    // Make a copy of the input label to modify
    string cleanedLabel = label;

    // Remove commas
    cleanedLabel.erase(remove(cleanedLabel.begin(), cleanedLabel.end(), ','), cleanedLabel.end());

    // Remove spaces
    cleanedLabel.erase(remove(cleanedLabel.begin(), cleanedLabel.end(), ' '), cleanedLabel.end());
    return cleanedLabel;
}

int main() {
    unordered_map<string, string> OPTAB;
    unordered_map<string, string> SYMTAB;
    unordered_map<string, string> REG;

    createOptab(OPTAB);
    createRegister(REG);

    ifstream infile("code.txt");
    //ifstream infile("code1.txt"); 
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    // Count the number of lines in the file
    while (getline(infile, line)) {
        lineCount++;
    }

    infile.clear(); 
    infile.seekg(0); 

    vector<vector<string>> words(lineCount, vector<string>(5)); // Initialize 2D vector
    int currentLine = 0;

    // inserting lines of txt file in 2-D vector
    while (getline(infile, line) && currentLine < lineCount) {
        line = removeExtraSpaces(line);
        istringstream iss(line);
        string word;
        int wordCount = 1;
        int length = 0;

        // Read up to the first two words
        while (iss >> word && wordCount < 3) {
            words[currentLine][wordCount] = word;
            wordCount++;
            length += word.length() + 1; // +1 accounts for the space between words
        }

        // Check if there is anything left for the third column
        if (length < line.size()) {
            // Safe extraction of substring for the third column
            words[currentLine][3] = line.substr(length);
        } else {
            words[currentLine][3] = "-"; // If nothing is left, assign an empty string
        }

        currentLine++;
    }


    infile.close();

    int Loc = stoi(words[0][3], nullptr, 16);   // starting address in integer form
    int startingAddress = Loc;

    // Initializing address for the next line
    words[1][0] = words[0][3];                  // initial address

    // Assigning the address of each line of the program
    for (int i = 1; i < lineCount - 1; i++) {
        string instruction = words[i][2];

        if (instruction[0] == '+') {
            string operand = instruction.substr(1);
            if (OPTAB.find(operand) == OPTAB.end()) {
                cout << "Operand not found." << endl;
                return 0;
            }
            Loc += 4;
        } else {
            if (OPTAB.find(instruction) != OPTAB.end() || instruction == "WORD") {
                string reg = words[i][3];
                int l = reg.length();

                if ((l == 1 && REG.find(string(1, reg[0])) != REG.end()) ||
                    (l == 3 && REG.find(string(1, reg[0])) != REG.end() && REG.find(string(1, reg[2])) != REG.end())) {
                    Loc += 2; // Register format
                } else {
                    Loc += 3; // General case
                }
            }  else if (instruction == "BYTE") {
                string str = words[i][3];
                if (str[0] == 'X') {
                    Loc += (str.length() - 3) / 2; // Adjust for hexadecimal
                } else if (str[0] == 'C') {
                    Loc += str.length() - 3; // Adjust for character
                }
            } else if (instruction == "RESW") {
                Loc += 3 * stoi(words[i][3]); // Reserved words
            } else if (instruction == "RESB") {
                Loc += stoi(words[i][3]); // Reserved bytes
            }
        }

        // Convert Loc to hex string with leading zeros and store it
        ostringstream oss;
        oss << hex << uppercase << setw(4) << setfill('0') << Loc;
        if (i + 1 < lineCount - 1)
            words[i + 1][0] = oss.str(); // Assign next line's address

        // Update symbol table
        if (words[i][1] != "-") { // If there's a label
            if (createSymtab(SYMTAB, words[i][0], cleanLabel(words[i][1]))) {
                continue;
            }
            else {
                cout << "Error !! Duplicate Symbol: " << words[i][1] << endl;
            }
        }
    }

/*
    for (auto itr : SYMTAB){
        cout << itr.first << " " << itr.second << endl;
    }
*/

    // Calculating the object code of each line 
    for (int i = 1; i < lineCount - 1; i++) {
        string instruction = words[i][2];
        string label = words[i][3];
        string objectCode = ""; 
        int l = label.size();
        int address; 
        int disp; 
        int e = 0;
        int x = 0;

        // Generate object code for the instruction
        if (instruction == "RSUB") {
            objectCode = "4C0000";      // Fixed object code for RSUB
        } else if (instruction == "WORD") {
            int value = stoi(words[i][3]); // Assuming decimal input
            ostringstream oss;
            oss << hex << uppercase << setw(6) << setfill('0') << value; // Format as hex
            objectCode = oss.str();
        } else if (instruction == "BYTE") {
            string str = words[i][3];
            if (str[0] == 'X') {
                objectCode = str.substr(2, str.length() - 3); // Get hex digits
            } else if (str[0] == 'C') {
                for (char ch : str.substr(2, str.length() - 3)) { // Skip C' and last '
                    ostringstream oss;
                    oss << hex << uppercase << setw(2) << setfill('0') << (int)ch; // Convert to hex
                    objectCode += oss.str(); // Append hex value
                }
            }
            
        } else if (instruction == "RESW") {
            continue;
        } else if (instruction == "RESB") {
            continue;
        }else if (l == 1 && REG.find(string(1, label[0])) != REG.end()){
            objectCode += OPTAB[instruction];
            objectCode += REG[(string(1, label[0]))];
            objectCode += "0";
        }
        else if (l == 3 && REG.find(string(1, label[0])) != REG.end() && REG.find(string(1, label[2])) != REG.end() ){
            objectCode += OPTAB[instruction];
            objectCode += REG[(string(1, label[0]))];
            objectCode += REG[(string(1, label[3]))];
        }else {
            // Handle other instructions (e.g., LDA, STA)
            string operand = (instruction[0] == '+') ? instruction.substr(1) : instruction;
            e = (instruction[0] == '+') ? 1 : 0;

            // Check if the operand exists in OPTAB
            if (OPTAB.find(operand) == OPTAB.end()) {
                cerr << "Operand " << operand << " not found in OPTAB." << endl;
            }

            // Convert the instruction's opcode to an integer
            address = stoi(OPTAB[operand], nullptr, 16);

            // Determine addressing mode and displacement
            if (!label.empty() && label[0] == '#') { // Immediate addressing
                address |= 0x01;
                disp = stoi(label.substr(1));
            } else if (!label.empty() && label[0] == '@') { // Indirect addressing
                address |= 0x02;
                disp = (SYMTAB.find(label.substr(1)) != SYMTAB.end()) ? stoi(SYMTAB[label.substr(1)], nullptr, 16) : 0;
            } else { // Simple addressing
                address |= 0x03;
                string symbol = "";

                // Extract label from the string
                for (char ch : label) {
                    if (ch != ',') {
                        symbol += ch;
                    } else {
                        x = 1; // Indicates indexed addressing
                        break;
                    }
                }

                if (SYMTAB.find(symbol) != SYMTAB.end()) {
                    int targetAddr = stoi(SYMTAB[symbol], nullptr, 16);
                    int pc = stoi(words[i+1][0], nullptr, 16);
                    if (!e) {  // If not in extended format
                        disp = targetAddr - pc; // PC-relative addressing (next instruction)

                        // Ensure `disp` is within -2048 to 2047
                        if (disp < -2048 || disp > 2047) {
                            cerr << "Error: PC-relative displacement out of bounds for " << symbol << endl;
                        }
                    } else {
                        disp = targetAddr; // Use full address for extended format
                    }
                } else {
                    cerr << "Warning: Label " << symbol << " not found in SYMTAB." << endl;
                }
            }

            // Construct the final object code
            ostringstream oss;
            oss << hex << uppercase << setw(2) << setfill('0') << address;
            objectCode += oss.str();

            int flags = (x << 3) | e;
            if (!label.empty() && label[0] != '#') { // Immediate addressing
                flags |= 2;
            }
            ostringstream ossFlags;
            ossFlags << hex << uppercase << setw(1) << setfill('0') << flags;
            objectCode += ossFlags.str();

            ostringstream ossDisp;
            int dispWidth = e ? 5 : 3; // Use 5-digit displacement for extended, else 3
            ossDisp << hex << uppercase << setw(dispWidth) << setfill('0') 
                    << (disp & ((1 << (dispWidth * 4)) - 1)); // Masking to fit displacement width
            objectCode += ossDisp.str();

        }
        words[i][4] = objectCode; // Store the object code
        
    }

    // Display the program with labels, opcodes, and operands
    cout << "The program with object codes is:\n";
    for (int i = 0; i < lineCount; ++i) {
        for (const auto& w : words[i]) {
            cout << w << " "; // Print each word in the line
        }
        cout << endl; // New line after each line's words
    }

    int lengthProgram = Loc - startingAddress;
    ostringstream oss;
    oss << hex << uppercase << setw(4) << setfill('0') << lengthProgram;
    string len = oss.str();

    cout << "\nObject Program:\n";

    // Header Record
    string programName = words[0][1];
    cout << "H" << setw(6) << left << programName.substr(0, 6) 
         << setfill('0') << right << setw(6) << hex << uppercase << startingAddress
         << setw(6) << len << endl;

    // Text Records
    int textRecordStart = startingAddress;
    int textRecordLength = 0;
    string objectCodeText = "";
    string textRecord = "T";

    for (int i = 1; i < lineCount - 1; i++) {
        if (!words[i][4].empty()) {
            int wordLength = words[i][4].length() / 2;

            // Check if adding this object code would exceed 30 bytes
            if (textRecordLength + wordLength > 30) {
                // Print the current text record and reset it
                cout << textRecord 
                     << setw(6) << setfill('0') << hex << textRecordStart
                     << setw(2) << textRecordLength << objectCodeText << endl;

                // Start a new text record
                textRecordStart = stoi(words[i][0], nullptr, 16);
                textRecordLength = 0;
                objectCodeText = "";
            }

            // Add current line's object code to the text record
            textRecordLength += wordLength;
            objectCodeText += words[i][4];
        }else {
            if (textRecordLength != 0){
                cout << textRecord 
                        << setw(6) << setfill('0') << hex << textRecordStart
                        << setw(2) << textRecordLength << objectCodeText << endl;

                    // Start a new text record
                    textRecordStart = stoi(words[i][0], nullptr, 16);
                    textRecordLength = 0;
                    objectCodeText = "";
            }
            else{
                textRecordStart = stoi(words[i+1][0], nullptr, 16);
            }
        }
    }

    // Print any remaining text record content
    if (!objectCodeText.empty()) {
        cout << textRecord 
             << setw(6) << setfill('0') << hex << textRecordStart
             << setw(2) << textRecordLength << objectCodeText << endl;
    }

    // End Record
    cout << "E" << setw(6) << setfill('0') << hex << uppercase << startingAddress << endl;


    return 0;
}

/*
Compile using:
g++ -std=c++11 -o sic_xe sic_xe.cpp table.cpp
*/