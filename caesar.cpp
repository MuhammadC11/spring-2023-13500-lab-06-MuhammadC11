#include <iostream>
#include <string>
#include "caesar.h"
#include <cctype>
#include "vigenere.h"
#include "decrypt.h"

// add functions here
char shiftChar(char c, int rshift)
{
    int shift = rshift % 26;   // if the shift is greater than 26, it will be reduced to a number between 0 and 25
    int num = (int)c;          // the character is converted to an integer
    if (num >= 65 && num < 97) // if the character is a capital letter (between 65 and 97)
    {
        return (char)((c - 65 + shift) % 26 + 65); // the character is shifted by the shift value and then converted back to a character
    }

    else if (num >= 97) // if the character is a lowercase letter
    {
        return (char)((c - 97 + shift) % 26 + 97); // the character is shifted by the shift value and then converted back to a character
    }

    else
    {
        return c; // if the character is not a letter, it is returned as is
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
