#include <iostream>
#include <string>
#include "vigenere.h"
#include <cctype>
#include "caesar.h"
// what i want to do is take the keyword and strip it of its ascii value so that it "a" starts at 0 and then stops at "z" which is 25. then i want to take the shift value and add it to the ascii value of the character.

//
char shiftKeyChar(char c, int &rshift)
{
    int shift = (int)rshift % 97;
    int num = (int)c;
    if (num >= 65 && num < 97)
    {
        return (char)((c - 65 + shift) % 26 + 65);
    }

    else if (num >= 97)
    {
        return (char)((c - 97 + shift) % 26 + 97);
    }

    else
    {
        return c;
    }

    return ' ';
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{

    std::string newSent;
    int keyIndex = 0;
    int keyValue = 0;

    for (int j = 0; j < plaintext.length(); j++)
    {
        keyValue = (int)keyword[keyIndex % keyword.length()] - 97;

                char c = plaintext[j]; // the first character of the sentence is stored in c
        if (isalpha(c))        // if the character is a letter
        {
            newSent += shiftKeyChar(c, keyValue); // add the shifted character to the new sent
            keyIndex++;
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
//     std::cout << encryptVigenere("Hello, World!", "cake") << std::endl;
//     return 0;
// }