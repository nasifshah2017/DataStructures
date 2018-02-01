// Filename: Assignment 1.cpp
//------------------------------
// Author: Syed Nasif Ali (201304650)
// Course: CSCI 162
// Date: 21 January 2016
// Purpose: Encryption and Decryption of a file, using two choices



#include <iostream>
#include <fstream>

using namespace std;

// Function Declaration

bool EnCrypt (ifstream&, ofstream&, int, int);
bool DeCrypt (ifstream&, ofstream&, int, int);

int main()
{
    int value, KeyValue, encryp, decryp;
    ifstream inFile;
    ofstream outFile;
    int Array[50];
    char ch;

    cout << "Select your choice \n\n 1. Encrypt or 2.Decrypt\n";
    cin >> value;

    if (value < 1 || value > 2)
    {
        cout << " Sorry your choice is invalid \n";
        return false;
    }

    inFile.open ("Programming.txt");

    if (inFile.fail())
    {
        cout << " Cannot find file \n";
        return false;
    }

    if (value == 1)
    {
        cout << " Please enter your key value \n";
        cin >> KeyValue;

        cout << " 1. shift 2. columnar transposition\nChoice:";
        cin >> encryp;

        EnCrypt(inFile, outFile, KeyValue, encryp);
    }



    else
    {
        cout << " Please enter your key value \n";
        cin >> KeyValue;

    }

   if (value == 2)
    {
        cout << " Please enter your key value \n";
        cin >> KeyValue;

        cout << " 1. shift 2. columnar transposition\nChoice:";
        cin >> decryp;

       DeCrypt(inFile, outFile, KeyValue, decryp);

    }



    return 0;

}

// Function: Encryption
// Usage: To Encrypt the file
// ---------------------------
// The function encrypts the text
// file using shift and columnar transposition

bool EnCrypt(ifstream& inFile, ofstream& outFile, int KeyValue, int encryp)
{
    int i;

    if (encryp == 1)
    {
        char ch = inFile.get();

        while (!inFile.eof())
        {
            ch = ch + KeyValue;

            if (ch > 126)
                ch = (ch % 126) + 32;

            cout << ch;
            ch = inFile.get();
        }
        outFile.open ("EnCryptProg.txt");
        outFile << ch;
        outFile.close();
    }
    else if (encryp == 2)
    {
        int length = 0;
        char array [100];
        char ch = inFile.get();

        while (!inFile.eof())
        {
            array[length] = ch;
            length++;
            ch = inFile.get();
        }

        for(int k=0 ; k<KeyValue ; k++)
        {
            int j = k;
            while(j < length)
            {
                cout << array[j];
                j = j + KeyValue;
            }
        }

        outFile.open ("EnCryptProg.txt");

        if (outFile.fail())
    {
        cout << "Unable to create Encrypt file!" << endl;
        outFile.close();
        return 0;
    }

      else
      {
        outFile << ch << "\n";
        outFile.close();
      }
    }


}

// Function: Decryption
// Usage: To Decrypt the file
// ---------------------------
// The function decrypts the text
// file

bool DeCrypt(ifstream& inFile, ofstream& outFile, int KeyValue, int decryp)
{
    int i;

   if (inFile.fail())
    {
        cout << "Cannot find file \n";
        return false;
    }
   if (decryp == 1)
    {
        char ch = inFile.get();

        while (!inFile.eof())
        {
            ch = ch - KeyValue;
            if (ch > 126)
            ch = (ch % 126) - 32;
            cout << ch;
            ch = inFile.get();
        }

}
}
