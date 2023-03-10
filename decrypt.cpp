#include <iostream>
#include <string>
#include <cctype>
#include "vigenere.h"
#include "caesar.h"

char leftShift(char c, int lshift)
{
    int num = (int)c;

    if (num >= 65 && num < 97)
    {
        return (char)(25 - (25 - (c - 65) + lshift) % 26 + 65);
    }

    else if (num >= 97)
    {
        return (char)(25 - (25 - (c - 97) + lshift) % 26 + 97);
    }

    else
    {
        return c;
    }

    return ' ';
}

std::string decryptCaesar(std::string ciphertext, int shift)
{
    std::string newSent;
    for (int i = 0; i < ciphertext.length(); i++) // loop through the sentence
    {

        char c = ciphertext[i]; // the first character of the sentence is stored in c
        if (isalpha(c))         // if the character is a letter
        {
            newSent += leftShift(c, shift); // add the shifted character to the new sentence
        }
        else
        {
            newSent += c; // if the character is not a letter, add it to the new sentence
        }
    }
    return newSent;
}

std::string decryptVigenere(std::string sentence, std::string keyword)
{
    std::string newSent;
    int keyIndex = 0;
    int keyValue = 0;

    for (int i = 0; i < sentence.length(); i++) // loop through the sentence
    {
        keyValue = (int)keyword[keyIndex % keyword.length()] - 97;

        char c = sentence[i]; // the first character of the sentence is stored in c
        if (isalpha(c))       // if the character is a letter
        {
            newSent += leftShift(c, keyValue); // add the shifted character to the new sentence
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
//     std::cout << decryptCaesar("Rovvy, Gybvn!", 10) << std::endl;
//     std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;
//     return 0;
// }