#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  std::cout << encryptCaesar("Hello World!", 3) << std::endl;
  std::cout << decryptCaesar("Khoor Zruog!", 3) << std::endl;
  std::cout << encryptVigenere("Hello, World!", "cake") << std::endl;
  std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;

    return 0;
}
