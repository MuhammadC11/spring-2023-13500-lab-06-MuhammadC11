#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here

TEST_CASE("Caesar")
{
    CHECK(encryptCaesar("Hey Whats Up", 5) == "Mjd Bmfyx Zu");
    CHECK(encryptCaesar("Nothing Much!", 5) == "Stymnsl Rzhm!");
    CHECK(encryptCaesar("I have 3 dollars", 5) == "N mfaj 3 itqqfwx");
}

TEST_CASE("Vigenere")
{
    CHECK(encryptVigenere("Hey Whats Up", "abc") == "Hfa Wictt Wp");
    CHECK(encryptVigenere("Nothing Much!", "abc") == "Npvhjpg Nwci!");
    CHECK(encryptVigenere("I have 3 dollars", "abc") == "I icvf 3 fomnasu");
}
TEST_CASE("Decrypt")
{
    CHECK(decryptVigenere("Hfa Wictt Wp", "abc") == "Hey Whats Up");
    CHECK(decryptVigenere("Npvhjpg Nwci!", "abc") == "Nothing Much!");
    CHECK(decryptVigenere("I icvf 3 fomnasu", "abc") == "I have 3 dollars");
    CHECK(decryptCaesar("N mfaj 3 itqqfwx", 5) == "I have 3 dollars");
}