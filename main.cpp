#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <vector>
#include <cmath>

int main()
{
  // std::cout << encryptCaesar("Hello World!", 3) << std::endl;
  // std::cout << decryptCaesar("Khoor Zruog!", 3) << std::endl;
  // std::cout << encryptVigenere("Hello, World!", "cake") << std::endl;
  // std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;
  std::string test0 = "Aopz pz qbza h alza.";
  std::string test1 = "Le tlt texq x qbpq";
  std::string test2 = "Rxewtgts pcs Strxewtgts";

  std::vector<double> t0;
  std::vector<double> t1;
  std::vector<double> t2;

  t0 = allFreq(test0);
  t1 = allFreq(test1);
  t2 = allFreq(test2);

  std::cout << letterFreq('a', test0) << "\n";
  std::cout << letterFreq('l', test1) << "\n";
  std::cout << letterFreq('t', test2) << "\n";

  std::cout << vDistance(t0) << "\n";
  std::cout << vDistance(t1) << "\n";
  std::cout << vDistance(t2) << "\n";

  std::cout << solve(test0) << "\n";
  std::cout << solve(test1) << "\n";
  std::cout << solve(test2) << "\n";

  return 0;
}
