  writeSymTabintoFile(locArr , symbolsArr , instArr , refArr , (sizeof(instArr) / sizeof(instArr[0])) );


  for (int i = 0 ; i < (sizeof(instArr) / sizeof(instArr[0])) ; i++){
        string temp = instArr[i];
        if (temp.substr(0 , 1) == "+"){
            temp = instArr[i].substr(1 , instArr[i].length() - 1);
        }
        if (temp == "START" || temp == "BASE" || temp == "RESB" || temp == "RESW" || temp == "END"){
            objArr[i] = "";
        }
        else if (temp == "BYTE"){
            string byte = refArr[i];
            char tempArr[byte.length()];
            strcpy(tempArr, byte.c_str());
            if (tempArr[0] == 'X' || tempArr[0] == 'x'){
                objArr[i] = byteXopcode(byte);
            }
            else if (tempArr[0] == 'C' || tempArr[0] == 'c'){
                objArr[i] = byteCopcode(byte);
            }
        }
        else if (temp == "WORD"){
            string word = convertDecToHex(convertStringToInt(refArr[i]));
            if (word.length() == 1)
                word = "00000" + word;
            else if (word.length() == 2)
                word = "0000" + word;
            else if (word.length() == 3)
                word = "000" + word;
            else if (word.length() == 4)
                word = "00" + word;
            else if (word.length() == 5)
                word = "0" + word;
            objArr[i] = word;
        }
        else if (temp == "RSUB"){
            string opRsub = searchOpCode(temp);
            string opRbits = convertHexToBin(opRsub).substr(0 , 6);
            opRbits = opRbits + "1" + "1"; // n i
            objArr[i] = convertBinToHex(opRbits) + "0000";
        }
        else if (searchFormat2(temp) == 1){
            string opForm2 = searchOpCode(temp);
            if (refArr[i].length() == 5){
                opForm2 += searchRegOpCode(refArr[i].substr(0 , 2));
                opForm2 += searchRegOpCode(refArr[i].substr(3 , refArr[i].length() - 1));
            }
            else if (refArr[i].length() == 4){
                if (refArr[i].substr(0 , 2) == "PC" || refArr[i].substr(0 , 2) == "SW"){
                    opForm2 += searchRegOpCode(refArr[i].substr(0 , 2));
                    opForm2 += searchRegOpCode(refArr[i].substr(3 , refArr[i].length() - 1));
                }
                else {
                    opForm2 += searchRegOpCode(refArr[i].substr(0 , 1));
                    opForm2 += searchRegOpCode(refArr[i].substr(2 , refArr[i].length() - 1));
                }
            }
            else if (refArr[i].length() == 3){
                if (checkIfNumber(refArr[i].substr(2 , refArr[i].length() - 1)) == 1){
                    opForm2 += searchRegOpCode(refArr[i].substr(0 , 1));
                    opForm2 += refArr[i].substr(2 , refArr[i].length() - 1);
                }
                else{
                    opForm2 += searchRegOpCode(refArr[i].substr(0 , 1));
                    opForm2 += searchRegOpCode(refArr[i].substr(2 , refArr[i].length() - 1));
                }
            }
            else if (refArr[i].length() == 2){
                opForm2 += searchRegOpCode(refArr[i]);
            }
            else if (refArr[i].length() == 1){
                opForm2 += searchRegOpCode(refArr[i]);
            }
            if (opForm2.length() == 3){
                opForm2 = opForm2 + "0";
            }
            objArr[i] = opForm2;
        }

        else if (searchFormat1(temp) == 1){
            string opForm1 = searchOpCode(temp);
            objArr[i] = opForm1;
        }
        else if (instArr[i].substr(0 , 1) == "+"){
            string opForm4 = searchOpCode(temp);
            string bits6Op = convertHexToBin(opForm4).substr(0 , 6); // 6 bits op code
            string n4 , i4 , x4 , b4 , p4 , e4;
            string symbolLocation = "";
            e4 = n4 = i4 = "1";
            x4 = b4 = p4 = "0";
            symbolLocation = searchForLocation(refArr[i]);
            if (refArr[i].substr(0 , 1) == "#"){
                n4 = "0";
                if (checkIfNumber(refArr[i].substr(1 , refArr[i].length())) == 1){
                    symbolLocation = convertDecToHex(convertStringToInt(refArr[i].substr(1 , refArr[i].length())));
                }
                else
                    symbolLocation = searchForLocation(refArr[i].substr(1 , refArr[i].length()));
            }
            if (refArr[i].substr(0 , 1) == "@"){
                i4 = "0";
                symbolLocation = searchForLocation(refArr[i].substr(1 , refArr[i].length()));
            }
            if (isIndexBased(refArr[i]) == 1){
                x4 = "1";
                symbolLocation = searchForLocation(refArr[i].substr(0 , refArr[i].length() - 2));
            }
            if (isIndexBased(refArr[i]) == 1 && refArr[i].substr(0 , 1) == "@"){
                i4 = "0";
                x4 = "1";
                symbolLocation = searchForLocation(refArr[i].substr(1 , refArr[i].length() - 3));
            }
            if (isIndexBased(refArr[i]) == 1 && refArr[i].substr(0 , 1) == "#"){
                n4 = "0";
                x4 = "1";
                symbolLocation = searchForLocation(refArr[i].substr(1 , refArr[i].length() - 3));
            }
            string nixbpe4 = n4 + i4 + x4 + b4 + p4 + e4;
            opForm4 = bits6Op + nixbpe4;
            symbolLocation = "0" + symbolLocation;
            objArr[i] = convertBinToHex(opForm4) + symbolLocation;
        }
        else if (instArr[i].substr(0 , 1) != "+" && searchFormat1(temp) != 1 && searchFormat2(temp) != 1 && instArr[i] != ""){
            int flag = 0;
            string opForm3 = searchOpCode(temp);
            string bits6Op3 = convertHexToBin(opForm3).substr(0 , 6);
            string n3 , i3 , x3 , b3 , p3 , e3;
            string symbolDisp = "";
            n3 = i3 = p3 = "1";
            x3 = b3 = e3 = "0";
            symbolDisp = searchForLocation(refArr[i]);
            if (refArr[i].substr(0 , 1) == "#"){
                n3 = "0";
                if (checkIfNumber(refArr[i].substr(1 , refArr[i].length())) == 1){
                    symbolDisp = convertDecToHex(convertStringToInt(refArr[i].substr(1 , refArr[i].length())));
                    p3 = "0";
                    flag = 1;
                }
                else
                    symbolDisp = searchForLocation(refArr[i].substr(1 , refArr[i].length()));
            }
            if (refArr[i].substr(0 , 1) == "@" && flag == 0){
                i3 = "0";
                symbolDisp = searchForLocation(refArr[i].substr(1 , refArr[i].length()));
            }
            if (isIndexBased(refArr[i]) == 1 && flag == 0){
                x3 = "1";
                symbolDisp = searchForLocation(refArr[i].substr(0 , refArr[i].length() - 2));
            }
            if (isIndexBased(refArr[i]) == 1 && refArr[i].substr(0 , 1) == "@" && flag == 0){
                i3 = "0";
                x3 = "1";
                symbolDisp = searchForLocation(refArr[i].substr(1 , refArr[i].length() - 3));
            }
            if (isIndexBased(refArr[i]) == 1 && refArr[i].substr(0 , 1) == "#" && flag == 0){
                n3 = "0";
                x3 = "1";
                symbolDisp = searchForLocation(refArr[i].substr(1 , refArr[i].length() - 3));
            }
            int pc , base;
            if (locArr[i + 1] == ""){
                pc = convertHexToDec(locArr[i + 2]);
            }
            else
                pc = convertHexToDec(locArr[i+1]);
            if (checkIfPcRelative(convertHexToDec(symbolDisp) - pc) == 0 && flag == 0){
                p3 = "0";
                b3 = "1";
                base = searchForBaseValue(locArr  , symbolsArr , instArr , refArr , sizeof(instArr)/sizeof(instArr[0]));
                symbolDisp = convertDecToHex(convertHexToDec(symbolDisp) - base);
            }
            else if (checkIfPcRelative(convertHexToDec(symbolDisp) - pc) == 1 && flag == 0){
                symbolDisp = convertDecToHex(convertHexToDec(symbolDisp) - pc);
            }
            string nixbpe3 = n3 + i3 + x3 + b3 + p3 + e3;
            opForm3 = bits6Op3 + nixbpe3;
            if (symbolDisp.length() == 1){
                symbolDisp = "00" + symbolDisp;
            }
            else if (symbolDisp.length() == 2){
                symbolDisp = "0" + symbolDisp;
            }
            if (opForm3.substr(0 , 4) == "0000"){
                opForm3 = "0" + convertBinToHex(opForm3);
                objArr[i] = opForm3 + symbolDisp;
            }
            else
                objArr[i] = convertBinToHex(opForm3) + symbolDisp;
            if (objArr[i].length() > 8){
                objArr[i] = objArr[i].substr(0 , 3) + objArr[i].substr(objArr[i].length() - 3 , objArr[i].length());
            }
        }


    }

    writeObjTabintoFile(locArr , symbolsArr , instArr , refArr , objArr , sizeof(instArr)/sizeof(instArr[0]));

    string hRecord = symbolsArr[0];
    if (hRecord.length() == 4){
        hRecord = hRecord + "__";
    }
    else if (hRecord.length() == 5){
        hRecord = hRecord + "_";
    }
    string startAddress = locArr[0];
    if (startAddress.length() == 4){
        startAddress = "00" + startAddress;
    }
    else if (startAddress.length() == 5){
        startAddress = "0" + startAddress;
    }
    string programLength = convertDecToHex(convertHexToDec(endAddress) - convertHexToDec(startAddress));
    if (programLength.length() == 4){
        programLength = "00" + programLength;
    }
    else if (programLength.length() == 5){
        programLength = "0" + programLength;
    }
    hRecord = "H^" + hRecord + "^" + startAddress + "^" + programLength;
    string endRecord = "E^"+startAddress;

    vector <string> tRecord;
    vector <string> mRecord;
    vector <string> temp;
    int textRLength = 0;
    int flag = 0;
    int first = 0;
    int cnt = 0;
    string lastAddress = "";

    for (int i = 0 , j = 0 ; i < sizeof(objArr)/sizeof(objArr[0]) ; i++ , j++){
        if (flag == 0){
            if (first == 0){
                tRecord.push_back("T^" + startAddress + "^");
                first = 1;
            }
            if (textRLength + objArr[i].length() / 2 <= 30){
                textRLength += objArr[i].length() / 2;
                temp.push_back(objArr[i]);
            }
            if (textRLength + objArr[i].length() / 2 >= 30){
                textRLength = 0;
                flag = 1;
                lastAddress = locArr[i + 1];
                tRecord.push_back(convertDecToHex(convertHexToDec(locArr[i + 1]) - convertHexToDec(startAddress))+"^");
                tRecord.insert(tRecord.end() , temp.begin() , temp.end());
                tRecord.push_back("\n");
                temp.clear();
            }
        }
        else if (flag == 1){
            if (first == 1){
                if (lastAddress.length() == 4)
                    lastAddress = "00" + lastAddress;
                else if (lastAddress.length() == 5)
                    lastAddress = "0" + lastAddress;
                tRecord.push_back("T^" + lastAddress + "^");
                first = 0;
            }
            if (textRLength + objArr[i].length() / 2 <= 30){
                textRLength += objArr[j].length() / 2;
                temp.push_back(objArr[j]);
            }
            if (textRLength + objArr[i].length() / 2 >= 30 || instArr[i] == "RESW" || instArr[i] == "RESB" || instArr[i] == "END"){
                textRLength = 0;
                string tLength = convertDecToHex(convertHexToDec(locArr[i]) - convertHexToDec(lastAddress));
                if (tLength.length() == 1){
                    tLength = "0" + tLength;
                }
                tRecord.push_back(tLength+"^");
                tRecord.insert(tRecord.end() , temp.begin() , temp.end());
                tRecord.push_back("\n");
                temp.clear();

                while (instArr[i] == "RESW" || instArr[i] == "RESB"){
                    i++;
                }
                j = i - 1;
                lastAddress = locArr[i];
                first = 1;
                if (instArr[i] == "END")
                    break;
            }
        }
    }

    for (int i = 0 ; i < sizeof(objArr) / sizeof(objArr[0]) ; i++){
        if (objArr[i].length() == 8){
            string tempLoc = locArr[i];
            tempLoc = convertDecToHex(convertHexToDec(tempLoc) + 1);
            if (tempLoc.length() == 5)
                tempLoc = "0" + tempLoc;
            else if (tempLoc.length() == 4)
                tempLoc = "00" + tempLoc;
            else if (tempLoc.length() == 3)
                tempLoc = "000" + tempLoc;
            else if (tempLoc.length() == 2)
                tempLoc = "0000" + tempLoc;
            else if (tempLoc.length() == 1)
                tempLoc = "00000" + tempLoc;
            if (refArr[i].substr(0 , 1) == "#"){
                if (checkIfNumber(refArr[i].substr(1 , refArr[i].length())) == 0){
                    mRecord.push_back("M^" + tempLoc + "^05");
                }
            }
            else{
                mRecord.push_back("M^" + tempLoc + "^05");
            }
        }
    }

    writeHTEintoFile(hRecord , tRecord , mRecord , endRecord);


    cout << "Loc  |" << '\t' << "Symb  |" << '\t' << "Inst  |" << '\t' << " Ref   |" << "   Obj   |" << endl << "_____|________|_______|________|_________|" << endl;

  for (int i = 0 ; i < (sizeof(instArr) / sizeof(instArr[0])) ; i++){
        cout << locArr[i] << '\t' << symbolsArr[i] << '\t' << instArr[i] << '\t' << refArr[i] << '\t' << "  " << objArr[i] <<endl;
  }

  cout << hRecord << endl;

  for (int i = 0 ; i < tRecord.size() ; i++){
      cout << tRecord[i];
  }


  for (int i = 0 ; i < mRecord.size() ; i++){
        cout << mRecord[i] << endl;
  }

  cout << endRecord << endl;

  return 0;

}
