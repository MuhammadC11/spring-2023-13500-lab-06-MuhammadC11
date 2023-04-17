#pragma once
#include <iostream>
#include <string>
#include <vector>

std::string decryptCaesar(std::string sentence, int shift);
std::string decryptVigenere(std::string sentence, std::string keyword);
double letterFreq(char letter, std::string encrypted_string);
std::vector<double> allFreq(std::string encrypted_string);
double vDistance(std::vector<double> encryptedFreq);
std::string solve(std::string encrypted_string);