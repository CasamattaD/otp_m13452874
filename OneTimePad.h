#pragma once
#include <string>

class OneTimePad
{
private:
    std::string newKey;
    std::string key;
    std::string plainText;
    std::string cipherText;

public:

    void NewKeyGen(int newKeyLength);
    void Encrpyt();
    void Decrypt();

};