/* Filename: Lab13.cpp
 * --------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSCI 162
 * Date:   8 January 2015
 * Purpose: Read a text file and count the number of letters (isalpha),
 * digits (isdigit), punctuation symbols (ispunct), and whitespace
 * characters (isspace) in the file. At the end of the file, the program
 * is to display an appropriate report.
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char ch, ch2, word[30];
    int letters = 0, digits = 0, symbols = 0, characters = 0, counter = 0, sentences = 0;
    ifstream inFile;

    inFile.open("Text1.txt");

    if (inFile.fail())
    {
        cout << "Cannot find file!\n";
        return 0;
    }

    inFile.get(ch);

    while (!inFile.eof())
    {
        if (isalpha(ch)) letters++;
        else if (isdigit(ch)) digits++;
        else if (ispunct(ch)) symbols++;
        else if (isspace(ch)) characters++;
        if (ch == '.' || ch == '?' || ch == '!') sentences++;
        if (isspace (ch) && ! isspace(ch2)) counter++;
        ch2 = ch;
        inFile.get(ch);

    }

    inFile.close();

    cout << "Letters: " << letters << "\n"
         << "Digits:  " << digits << "\n"
         << "Punctuation Symbols: "  << symbols << "\n"
         << "Whitespace: " << characters << "\n"
         << "Words: " << counter << "\n"
         << "Sentences: " << sentences << "\n";

    return 0;
}
