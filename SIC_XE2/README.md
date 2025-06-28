# SIC-XE-ASSEMBLER
This project provides an assembler for the SIC/XE (Extended Instruction Set) architecture, building upon the base SIC assembler with support for extended addressing modes and additional features.
Table of Contents
Overview
Features
Usage
Files Included
Example Input and Output
Overview
The SIC/XE assembler extends the capabilities of the basic SIC assembler, supporting new instructions, addressing modes (e.g., indirect, immediate, and indexed), and extended formats. The assembler generates object code for each instruction, allowing SIC/XE programs to be executed or further processed.

Features
Support for Extended Instruction Set: Includes additional addressing modes (immediate, indirect, indexed) and extended format instructions.
OPTAB and SYMTAB: Stores and retrieves opcodes and symbols.
Object Code Generation: Outputs machine code with adjustments for SIC/XE-specific addressing modes.
Address Assignment: Calculates memory locations based on instruction length, using PC-relative and Base-relative addressing as needed.
Usage
Compiling the Code
Compile the assembler with:

bash
Copy code
g++ -std=c++11 -o sic_xe_assembler sic_xe_assembler.cpp table.cpp
Running the Assembler
bash
Copy code
./sic_xe_assembler
Ensure the assembly code file, code.txt, is in the same directory.

Input File (code.txt)
The file should contain SIC/XE assembly code, formatted with labels, instructions, and operands per the SIC/XE syntax.
