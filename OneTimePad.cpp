#include "OneTimePad.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include <string.h>

using namespace std;

// Convert a char type into it's 8 bit binary string value
string CharToBit(string textTemp){
    string bitTemp;

    for (int i = 0; i < textTemp.length(); i++)
    {
        bitset<8> temp(textTemp[i]);
        bitTemp.append(temp.to_string());
    }

    return bitTemp;
}

// Convert a inary string into its char values with groups of 8 bit binaries.
string BitToChar(string bitTemp){
    string textTemp;
    string bitGroup;
    for (int i = 0; i < bitTemp.length(); i+= 8)
    {
        bitGroup = bitTemp.substr(i, 8);
        bitset<8> temp(bitGroup);
        textTemp.push_back(temp.to_ulong());
    }
    
    return textTemp;
}

// Perform XOR function on binary strings and return its result
string XOR(string cipherTemp, string key){
    string xorTemp;
    for (int i = 0; i < key.length(); i++)
    {
        if (cipherTemp[i] == key[i])
        {
           xorTemp += "0"; 
        }else{
            xorTemp += "1";
        }
        
    }
    return xorTemp;
    
}

// Generate new key with specified length input by user
void OneTimePad::NewKeyGen(int newKeyLength)
{
    // Generate new key
    for (int i = 0; i < newKeyLength; i++)
    {
        newKey += to_string(((int)rand() % 2));
    }
    
    // Open files and write results to files
    ofstream outFile;
    outFile.open("./data/newkey.txt");
    outFile << newKey;
    outFile.close();
    cout << "Secret Key:\n" + newKey << endl;
}

// Encrypt a plaintext
void OneTimePad::Encrpyt()
{
    // Open files
    fstream keyFile("./data/key.txt");
    fstream plainFile("./data/plaintext.txt");
    ofstream cipherFile;
    cipherFile.open("./data/ciphertext.txt");
    getline(keyFile, key);
    getline(plainFile, plainText);

    if ((key.length() / 8) != plainText.length())
    {
        cout << "ERROR: length is incorrect!" << endl;
        return;
    }
    
    // Perform cipher operations
    string plainBit = CharToBit(plainText);
    string cipherTemp = XOR(plainBit, key);
    cipherText = BitToChar(cipherTemp);

    // Print values to terminal and file
    cipherFile << cipherText;
    cipherFile.close();
    cout << "Ciphertext: " << cipherText << endl;
}

// Decrypt function to find plaintext value of a ciphertext
void OneTimePad::Decrypt()
{
    // Open files
    fstream keyFile("./data/key.txt");
    fstream cipherFile("./data/ciphertext.txt");
    ofstream resultFile;
    resultFile.open("./data/result.txt");
    getline(keyFile, key);
    getline(cipherFile, cipherText);

    if ((key.length() / 8) != cipherText.length())
    {
        cout << "ERROR: length is incorrect!" << endl;
        return;
    }

    // Perform cipher operations
    string cipherBit = CharToBit(cipherText);
    string plainTemp = XOR(cipherBit, key);
    plainText = BitToChar(plainTemp);

    // Write results to terminal and files
    resultFile << plainText;
    resultFile.close();
    cout << "Plaintext: " << plainText << endl;
}

