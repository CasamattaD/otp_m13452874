#pragma once
#include <string>

class OneTimePad
{
private:
    // Initialize important variables
    std::string newKey;
    std::string key;
    std::string plainText;
    std::string cipherText;

public:

    // Initialize Encrypt, Decrypt, New Key Generation functions
    void NewKeyGen(int newKeyLength);
    void Encrpyt();
    void Decrypt();

};