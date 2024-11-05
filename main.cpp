#include "morse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main(void) {
    BSTnode morseTree;
    char letter = ' ';
    int count;
    string str, Pmorse;

    // Open input and output files
    ifstream ifile("Convert.txt");
    ofstream ofile("Output.txt");

    if (!ifile) {
        cerr << "Error opening input file.\n";
        return 1;
    }
    if (!ofile) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    morseTree.print(); // This will display the Morse code tree in the console

    // Translate each line in the input file
    while (getline(ifile, str)) {
        count = 0;
        while (letter = str[count]) {
            if (isspace(letter)) {
                ofile << "   ";  // Add spacing for words
            }
            else {
                if (islower(letter)) {
                    letter = toupper(letter);
                }
                morseTree.searchNode(letter, Pmorse);
                ofile << Pmorse << " "; // Write Morse code to output file
            }
            count++;
        }
        ofile << "\n";  // Newline after each line in input file
    }
    system("pause");
    // Close files
    ifile.close();
    ofile.close();

    return 0;
}