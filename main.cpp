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
  std::string test1 = "Vr slaz zll pm aopz dvyrz";
  std::string test2 = "Vo vr sla tl ruvd dolu pa dvyrz";
  std::string test3 = "slaz nv pa dvyrz!";
  std::string freq1 = "aabbcc";
  std::string freq2 = "cc";
  std::string freq3 = "bbcc";

  std::vector<double> t1;
  std::vector<double> t2;
  std::vector<double> t3;

  t1 = allFreq(test1);
  t2 = allFreq(test2);
  t3 = allFreq(test3);

  std::cout << letterFreq('a', freq1) << std::endl;
  std::cout << letterFreq('c', freq2) << std::endl;
  std::cout << letterFreq('b', freq3) << std::endl;

  std::cout << vDistance(t1) << std::endl;
  std::cout << vDistance(t2) << std::endl;
  std::cout << vDistance(t3) << std::endl;

  std::cout << solve(test1) << std::endl;
  std::cout << solve(test2) << std::endl;
  std::cout << solve(test3) << std::endl;

  return 0;
}
