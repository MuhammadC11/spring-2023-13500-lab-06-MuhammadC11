#include <iostream>
#include <string>
#include "caesar.h"
#include <cctype>
#include "vigenere.h"

// add functions here
char shiftChar(char c, int rshift)
{
    int shift = rshift % 26;
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

std::string encryptCaesar(std::string sentence, int shift)
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
//     std::cout << encryptCaesar(7, "Abcd Efg") << std::endl;
//     return 0;
// }