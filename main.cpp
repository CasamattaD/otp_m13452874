#include <iostream>
#include "OneTimePad.h"

using namespace std;

int main(int argc, char *argv[]){


    string func = argv[1];
    OneTimePad otp;
    
    // Generates new secret key if security parameter was passed through
    // in command-line
    if(argc > 2)
    {
        if (func == "keygen"){
            char *output;
            long argToInt = strtol(argv[2], &output, 10);
            if (argToInt > 0 & argToInt < 129)
            {
                otp.NewKeyGen(argToInt);
            }
            else{
                cout << "Invalid number entered... goodbye" << endl;
            }
        }
    }

    // Calls encrypt Function
    if (func == "enc")
    {
        otp.Encrpyt();
    }

    // Calls Decrypt Function
    if (func == "dec")
    {
        otp.Decrypt();
    }

    return 0;
}