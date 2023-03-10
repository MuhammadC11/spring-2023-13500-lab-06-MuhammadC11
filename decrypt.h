#pragma once
#include <string>

std::string decryptCaesar(std::string sentence, int shift);
std::string decryptVigenere(std::string sentence, std::string keyword);