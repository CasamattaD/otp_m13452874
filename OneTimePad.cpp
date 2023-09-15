#include "OneTimePad.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include <string.h>

using namespace std;
string CharToBit(string textTemp){
    string bitTemp;

    for (int i = 0; i < textTemp.length(); i++)
    {
        bitset<8> temp(textTemp[i]);
        bitTemp.append(temp.to_string());
    }

    return bitTemp;
}

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

void OneTimePad::NewKeyGen(int newKeyLength)
{
    for (int i = 0; i < newKeyLength; i++)
    {
        newKey += to_string(((int)rand() % 2));
    }
    
    ofstream outFile;
    outFile.open("./data/newkey.txt");
    outFile << newKey;
    outFile.close();
    cout << "Secret Key:\n" + newKey << endl;
}

void OneTimePad::Encrpyt()
{
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
    
    string plainBit = CharToBit(plainText);
    string cipherTemp = XOR(plainBit, key);
    cipherText = BitToChar(cipherTemp);

    cipherFile << cipherText;
    cipherFile.close();
    cout << "Ciphertext: " << cipherText << endl;
}

void OneTimePad::Decrypt()
{
    fstream keyFile("./data/key.txt");
    fstream cipherFile("./data/ciphertext.txt");
    ofstream plainFile;
    plainFile.open("./data/plaintext.txt");
    getline(keyFile, key);
    getline(cipherFile, cipherText);

    if ((key.length() / 8) != cipherText.length())
    {
        cout << "ERROR: length is incorrect!" << endl;
        return;
    }

    string cipherBit = CharToBit(cipherText);
    string plainTemp = XOR(cipherBit, key);
    plainText = BitToChar(plainTemp);

    plainFile << plainText;
    plainFile.close();
    cout << "Plaintext: " << plainText << endl;
}

