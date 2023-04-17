#include <iostream>
#include <string>
#include "caesar.h"
#include <cctype>
#include "vigenere.h"
#include "decrypt.h"
#include <vector>
#include <cmath>

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

double letterFreq(char letter, std::string encrypted_string) // create a function that takes a letter and a string and returns the frequency of the letter in the string
{
    double freq = 0;                                    // the frequency of the letter in the string starts at 0
    for (int i = 0; i < encrypted_string.length(); i++) // loop through the string
    {
        if (tolower(encrypted_string[i]) == letter) // if the character is the letter
        {
            freq += 1; // add 1 to the frequency
        }
    }
    freq /= encrypted_string.length(); // divide the frequency by the length of the string to get the percentage of the letter in the string.
    return freq;                       // return the frequency.
}

std::vector<double> allFreq(std::string encrypted_string) // create a function that takes a string and returns a vector of the frequencies of the letters in the string
{
    std::vector<char> englishAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // create a vector of the english alphabet
    std::vector<double> lFreq = {};                                                                                                                                         // create a vector to store the frequencies of the letters in the string
    for (int f = 0; f < englishAlphabet.size(); f++)                                                                                                                        // loop through the english alphabet
    {
        lFreq.push_back(letterFreq(englishAlphabet[f], encrypted_string)); // add the frequency of the letter to the vector. pushback is used because the vector is empty and the size is unknown.
    }
    return lFreq; // return the vector
}

double vDistance(std::vector<double> encryptedFreq) // create a function that takes a vector of frequencies and returns the distance between the vector and the english alphabet
{
    std::vector<double> englishFreq = {8.2, 1.5, 2.8, 4.3, 13, 2.2, 2, 6.1, 7, 0.15, 0.77, 4, 2.4, 6.7, 7.5, 1.9, 0.095, 6, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2, 0.074}; // create a vector of the frequencies of the english alphabet
    double distance;                                                                                                                                                   // create a variable to store the distance
    for (int n = 0; n < 26; n++)                                                                                                                                       // loop through the vector
    {
        distance += (pow((englishFreq[n] - encryptedFreq[n]), 2.0)); // add the distance between the two vectors to the distance variable
    }
    return sqrt(distance); // return the distance
}

std::string solve(std::string encrypted_string)
{
    std::string decrypted_string; // create a variable to store the decrypted string
    double minDistance = 100;     // set the minimum distance to a large number
    int shift = 0;                // set the shift to 0
    for (int i = 0; i < 26; i++)  // loop through the alphabet
    {
        std::string decrypted = encryptCaesar(encrypted_string, i); // decrypt the string with the current shift
        std::vector<double> freq = allFreq(decrypted);              // get the frequencies of the letters in the decrypted string
        double distance = vDistance(freq);                          // get the distance between the frequencies of the decrypted string and the english alphabet
        if (distance < minDistance)                                 // if the distance is less than the minimum distance
        {
            minDistance = distance; // set the minimum distance to the current distance
            shift = i;              // set the shift to the current shift
        }
    }                                                          // the shift that has the smallest distance is the correct shift
    decrypted_string = encryptCaesar(encrypted_string, shift); // decrypt the string with the shift that has the smallest distance
    return decrypted_string;                                   // return the decrypted string
}

// int main()
// {
//     std::cout << encryptCaesar(7, "Abcd Efg") << std::endl;
//     return 0;
// }