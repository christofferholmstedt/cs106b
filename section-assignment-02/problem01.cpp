// problem01.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Problem01
{

    // Print the number of occurences of each character (in the alphabet) within the given string.
    void CountLetters(std::string filename)
    {
        std::ifstream input_file;
        std::string line;
        std::vector<int> number_of_chars(26);

        std::vector<char> the_alphabet;
        for (int i=0; i < 26; i++)
        {
            the_alphabet.push_back( i + 65 );
        }
        

        // Open the file
        input_file.open(filename);
        
        // Open the file and read all lines one by one.
        while (input_file.good())
        {
            std::getline(input_file, line); 
            for (char & c : line)
            {
                switch (c)
                {
                case 'a':
                case 'A':
                    number_of_chars[0]++;
                    break;
                case 'b':
                case 'B':
                    number_of_chars[1]++;
                    break;
                case 'c':
                case 'C':
                    number_of_chars[2]++;
                    break;
                case 'd':
                case 'D':
                    number_of_chars[3]++;
                    break;
                case 'e':
                case 'E':
                    number_of_chars[4]++;
                    break;
                case 'f':
                case 'F':
                    number_of_chars[5]++;
                    break;
                case 'g':
                case 'G':
                    number_of_chars[6]++;
                    break;
                case 'h':
                case 'H':
                    number_of_chars[7]++;
                    break;
                case 'i':
                case 'I':
                    number_of_chars[8]++;
                    break;
                case 'j':
                case 'J':
                    number_of_chars[9]++;
                    break;
                case 'k':
                case 'K':
                    number_of_chars[10]++;
                    break;
                case 'l':
                case 'L':
                    number_of_chars[11]++;
                    break;
                case 'm':
                case 'M':
                    number_of_chars[12]++;
                    break;
                case 'n':
                case 'N':
                    number_of_chars[13]++;
                    break;
                case 'o':
                case 'O':
                    number_of_chars[14]++;
                    break;
                case 'p':
                case 'P':
                    number_of_chars[15]++;
                    break;
                case 'q':
                case 'Q':
                    number_of_chars[16]++;
                    break;
                case 'r':
                case 'R':
                    number_of_chars[17]++;
                    break;
                case 's':
                case 'S':
                    number_of_chars[18]++;
                    break;
                case 't':
                case 'T':
                    number_of_chars[19]++;
                    break;
                case 'u':
                case 'U':
                    number_of_chars[20]++;
                    break;
                case 'v':
                case 'V':
                    number_of_chars[21]++;
                    break;
                case 'w':
                case 'W':
                    number_of_chars[22]++;
                    break;
                case 'x':
                case 'X':
                    number_of_chars[23]++;
                    break;
                case 'y':
                case 'Y':
                    number_of_chars[24]++;
                    break;
                case 'z':
                case 'Z':
                    number_of_chars[25]++;
                    break;
                }
            }
        } 

        for (std::size_t index = 0; index < number_of_chars.size(); ++index)
        {
            // Make sure that we don't walk out of bounds in the_alphabet vector
            // when looping through the other vector.
            if (index < the_alphabet.size())
            {
                std::cout << the_alphabet[index] << ": " << number_of_chars[index] << std::endl;
            }
        }


        // Print some warning output if the file could not be open read until EOF
        if (!input_file.eof()) {
            std::cout << "File could not be opened." << std::endl << std::endl;
        }
    }

    // Start of processing
    void Run()
    {
        std::string wait_to_exit;
        std::string file_to_open = "scores.txt";

        // Start problem two
        std::cout << "############## START OF PROBLEM 01 ####################" << std::endl 
            << "What is the name of the file to read? (default: alphabet.txt)" << std::endl;

        // Get the name of the scores file from comand line
        getline(std::cin, file_to_open);

        if (file_to_open.empty()) {
            file_to_open = "alphabet.txt";
        }

        CountLetters(file_to_open);

        std::cout << "############## END OF PROBLEM 01 ####################" << std::endl;
        std::getline(std::cin, wait_to_exit);
    }
}