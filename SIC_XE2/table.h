// tables.h
#ifndef TABLES_H
#define TABLES_H

#include <unordered_map>
#include <string>

void createOptab(std::unordered_map<std::string, std::string>& OPTAB);
bool createSymtab(std::unordered_map<std::string, std::string>& SYMTAB , std::string address , std:: string symbol);
void createRegister(std::unordered_map<std::string, std::string>& REG );

#endif // TABLES_H
