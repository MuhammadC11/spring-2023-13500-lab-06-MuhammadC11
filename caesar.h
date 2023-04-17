#pragma once
#include <string>
// add prototypes here
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string sentence, int shift);
double letterFreq(char letter, std::string encrypted_string);
std::vector<double> allFreq(std::string encrypted_string);
double vDistance(std::vector<double> encryptedFreq);
std::string solve(std::string encrypted_string);