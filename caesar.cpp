#include <iostream>
#include <string>
#include "caesar.h"
#include <cctype>
#include "vigenere.h"

// add functions here
char shiftChar(char c, int rshift)
{
    if (isupper(c)) // if the character is uppercase
    {
        c = c + rshift; // shift the characters value by the shift value
        if (c > 'Z')    // if the characters ascii value is greater than "z" in ascii value after the shift..
        {
            c = c - 'Z' + 'A' - 1; // wrap around the alphabet first subtract the value bigger than max value which is the value for Z, then add the value for A, then subtract 1 to get the correct value. 95 - 90 + 65 - 1 = 69 which is the value for E.
        }
    }
    else if (islower(c))
    {
        c = c + rshift; // add the shift value to the characters ascii value
        if (c > 'z')    // if the lowercase letters value is greater than the maximum value for lowercase letters
        {
            c = c - 'z' + 'a' - 1; // wrap around the alphabet first subtract the value bigger than max value which is the value for z, then add the value for a, then subtract 1 to get the correct value. 122 - 122 + 97 - 1 = 96 which is the value for a.
        }
    }
    return c;
}

std::string CaesarCipher(int shift, std::string sentence)
{
    std::string newSent;
    for (int i = 0; i < sentence.length(); i++) // loop through the sentence
    {

        char c = sentence[i]; // the first character of the sentence is stored in c
        if (isalpha(c))       // if the character is a letter
        {
            newSent += shiftChar(c, shift); // add the shifted character to the new sentence
        }
        else
        {
            newSent += c; // if the character is not a letter, add it to the new sentence
        }
    }
    return newSent;
}

// int main()
// {
//     std::cout << CaesarCipher(7, "Abcd Efg") << std::endl;
//     return 0;
// }