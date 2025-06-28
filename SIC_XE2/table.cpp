// tables.cpp
#include "table.h"

void createOptab(std::unordered_map<std::string, std::string>& OPTAB) {
    OPTAB["ADD"] = "18";
    OPTAB["ADDF"] = "58";
    OPTAB["ADDR"] = "90";
    OPTAB["AND"] = "40";
    OPTAB["CLEAR"] = "B4";
    OPTAB["COMP"] = "28";
    OPTAB["COMPF"] = "88";
    OPTAB["COMPR"] = "A0";
    OPTAB["DIV"] = "24";
    OPTAB["DIVF"] = "64";
    OPTAB["DIVR"] = "9C";
    OPTAB["FIX"] = "C4";
    OPTAB["FLOAT"] = "C0";
    OPTAB["HIO"] = "F4";
    OPTAB["J"] = "3C";
    OPTAB["JEQ"] = "30";
    OPTAB["JGT"] = "34";
    OPTAB["JLT"] = "38";
    OPTAB["JSUB"] = "48";
    OPTAB["LDA"] = "00";
    OPTAB["LDB"] = "68";
    OPTAB["LDCH"] = "50";
    OPTAB["LDF"] = "70";
    OPTAB["LDL"] = "08";
    OPTAB["LDS"] = "6C";
    OPTAB["LDT"] = "74";
    OPTAB["LDX"] = "04";
    OPTAB["LPS"] = "D0";
    OPTAB["MUL"] = "20";
    OPTAB["MULF"] = "60";
    OPTAB["MULR"] = "98";
    OPTAB["NORM"] = "C8";
    OPTAB["OR"] = "44";
    OPTAB["RD"] = "D8";
    OPTAB["RMO"] = "AC";
    OPTAB["RSUB"] = "4C";
    OPTAB["SHIFTL"] = "A4";
    OPTAB["SHIFTR"] = "A8";
    OPTAB["SIO"] = "F0";
    OPTAB["SSK"] = "EC";
    OPTAB["STA"] = "0C";
    OPTAB["STB"] = "78";
    OPTAB["STCH"] = "54";
    OPTAB["STF"] = "80";
    OPTAB["STI"] = "D4";
    OPTAB["STL"] = "14";
    OPTAB["STS"] = "7C";
    OPTAB["STSW"] = "E8";
    OPTAB["STT"] = "84";
    OPTAB["STX"] = "10";
    OPTAB["SUB"] = "1C";
    OPTAB["SUBF"] = "5C";
    OPTAB["SUBR"] = "94";
    OPTAB["SVC"] = "B0";
    OPTAB["TD"] = "E0";
    OPTAB["TIO"] = "F8";
    OPTAB["TIX"] = "2C";
    OPTAB["TIXR"] = "B8";
    OPTAB["WD"] = "DC";
}

bool createSymtab(std::unordered_map<std::string, std::string>& SYMTAB , std::string address , std:: string symbol){
    if(SYMTAB.find(symbol) == SYMTAB.end()){
        SYMTAB[symbol] = address;
        return true;
    }
    return false;
}

void createRegister(std::unordered_map<std::string, std::string>& REG ){
    REG["A"] = "0";
    REG["x"] = "1";
    REG["L"] = "2";
    REG["B"] = "3";
    REG["S"] = "4";
    REG["T"] = "5";
    REG["F"] = "6";
    REG["PC"] = "7";
    REG["SW"] = "8";
}