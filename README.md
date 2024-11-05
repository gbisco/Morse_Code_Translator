# Morse Code Translator
This project is a Morse Code Translator written in C++. It takes a text input file and converts each letter into Morse code using a Binary Search Tree (BST) for fast lookup. The program outputs the translated Morse code into an output file.

# Table of Contents
Project Overview
Features
File Structure
How to Use
Input and Output
Dependencies
Compilation and Execution
License

# Project Overview
The Morse Code Translator reads characters from a text file, converts each character to its corresponding Morse code, and writes the translation to an output file. The Morse code mappings are stored in a Binary Search Tree, which allows efficient character lookup.

# Features
* Translates text to Morse code from a file.
* Supports both lowercase and uppercase letters.
* Outputs Morse code translation to an output text file.
* Binary Search Tree (BST) used for efficient Morse code mapping.

# File Structure
* main.cpp: Contains the main function, handles file input and output, and calls the translation function.
* morse.h: Header file with definitions for the BSTnode class and function declarations.
* morse.cpp: Contains the function definitions for the BSTnode class, including insertion, search, and printing of Morse code.
* MorseTable.txt: Text file that contains mappings from characters to Morse code (e.g., A -> .-).

# How to Use
* Modify Convert.txt to what you wish to translate
* Place MorseTable.txt in your solution folder
* Run the program to translate the text in Convert.txt to Morse code and output it to Output.txt

# Dependecies
Standard C++ libraries (<string>, <fstream>, <iostream>, <cctype>).

# License
This project is open-source and available for modification. You may freely use, modify, and distribute it for educational or personal purposes.
