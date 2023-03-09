#include <iostream>
#include <string>
#include <fstream>

void asciiValue()
{
    std::string sentence;                       // declares a string for my input sentence
    std::cout << "Input" << std::endl;          // asks the user to input a sentence
    getline(std::cin, sentence);                // get the whole line from the user cin to put into the sentence variable which includes spaces.
    for (int i = 0; i < sentence.length(); i++) // for each character in the length of the sentence string
    {
        char c = sentence[i];                                   // declare each character in the string into a char which changes with the for loop
        std::cout << sentence[i] << " " << (int)c << std::endl; // then output the character and the ascii value of the character with a single space into it.
    }
}

int main()
{
    asciiValue();
    return 0;
}