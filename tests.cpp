#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>

// add your tests here

// TEST_CASE("Caesar")
// {
//     CHECK(encryptCaesar("Hey Whats Up", 5) == "Mjd Bmfyx Zu");
//     CHECK(encryptCaesar("Nothing Much!", 5) == "Stymnsl Rzhm!");
//     CHECK(encryptCaesar("I have 3 dollars", 5) == "N mfaj 3 itqqfwx");
// }

// TEST_CASE("Vigenere")
// {
//     CHECK(encryptVigenere("Hey Whats Up", "abc") == "Hfa Wictt Wp");
//     CHECK(encryptVigenere("Nothing Much!", "abc") == "Npvhjpg Nwci!");
//     CHECK(encryptVigenere("I have 3 dollars", "abc") == "I icvf 3 fomnasu");
// }
// TEST_CASE("Decrypt")
// {
//     CHECK(decryptVigenere("Hfa Wictt Wp", "abc") == "Hey Whats Up");
//     CHECK(decryptVigenere("Npvhjpg Nwci!", "abc") == "Nothing Much!");
//     CHECK(decryptVigenere("I icvf 3 fomnasu", "abc") == "I have 3 dollars");
//     CHECK(decryptCaesar("N mfaj 3 itqqfwx", 5) == "I have 3 dollars");
// }
TEST_CASE("Letter Frequency")
{
    CHECK(letterFreq('a', "aabbcc") == doctest::Approx(0.333333));
    CHECK(letterFreq('c', "cc") == 1);
    CHECK(letterFreq('b', "bbcc") == 0.5);
}

std::string test1 = "Vr slaz zll pm aopz dvyrz";
std::string test2 = "Vo vr sla tl ruvd dolu pa dvyrz";
std::string test3 = "slaz nv pa dvyrz!";
std::string freq1 = "aabbcc";
std::string freq2 = "cc";
std::string freq3 = "bbcc";

std::vector<double> t1 = {0.3333,
                          0.3333,
                          0.3333,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0};
std::vector<double> t2 = {0.0,
                          0.0,
                          1.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0};
std::vector<double> t3 = {0.0,
                          0.5,
                          0.5,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0,
                          0.0};
TEST_CASE("Vector Distance")
{
    CHECK(vDistance(t1) == doctest::Approx(25.6143));
    CHECK(vDistance(t2) == doctest::Approx(25.6806));
    CHECK(vDistance(t3) == doctest::Approx(25.6962));
}
TEST_CASE("Solve")
{
    CHECK(solve("mjd bmfyx zu") == "hey whats up");
    CHECK(solve("Xlic gepp qi Nyer") == "They call me Juan");
}