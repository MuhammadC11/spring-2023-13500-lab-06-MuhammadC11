#include <iostream>
#include <string>
#include "vigenere.h"
#include <cctype>
#include "caesar.h"
// what i want to do is take the keyword and strip it of its ascii value so that it "a" starts at 0 and then stops at "z" which is 25. then i want to take the shift value and add it to the ascii value of the character.

//
char shiftKeyChar(char c, int &rshift)
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

std::string encryptVigenere(std::string plaintext, std::string keyword)
{

    std::string newSent;
    int keyValue = 0;
    int key = 0;
    for (int j = 0; j < plaintext.length(); j++)
    {
        keyValue = (int)keyword[j] - 97;
        std::cout << keyValue << std::endl;

        char c = plaintext[key]; // the first character of the sentence is stored in c
        if (isalpha(c))          // if the character is a letter
        {
            newSent += shiftKeyChar(c, keyValue); // add the shifted character to the new sentence
        }
        else
        {
            newSent += c; // if the character is not a letter, add it to the new sentence
        }
        key++;
        if (j == keyword.length() - 1)
        {
            j = -1;
        }
        if (key == plaintext.length())
        {
            break;
        }
    }

    return newSent;
}

// int main()
// {
//     std::cout << encryptVigenere("ABCDEFGHI", "aabbcc") << std::endl;
//     return 0;
// }