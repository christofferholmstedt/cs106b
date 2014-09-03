// problem02.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

namespace Problem02
{
    struct Results {
        int min;
        int max;
        int avg;
    };

    bool is_digit(const std::string &str)
    {
        return str.find_first_not_of("0123456789") == std::string::npos;
    }

    bool Line_is_Valid(std::string line)
    {
        int temp_int;
        // Only numbers in the line 
        if (is_digit(line))
        {
            temp_int = atoi(line.c_str());
            if (temp_int <= 100 && temp_int >= 0)
                return true;
            else
                return false;
        } else
        {
            return false;
        }

    }

    // Calculate score from file.
    Results CalculateScores(std::string filename)
    {
        Results temp_results = {100,0,0};
        std::ifstream input_file;
        std::string line;
        int temp_int;
        int sum = 0;
        int number_of_values = 0;

        // Open the file
        input_file.open(filename);
        
        // Open the file and read all lines one by one.
        while (input_file.good())
        {
           std::getline(input_file, line); 
           if (Line_is_Valid(line))
           {
               temp_int = atoi(line.c_str());

               // If the new number is bigger than previous max.
               if (temp_results.max < temp_int)
                   temp_results.max = temp_int;

               // If the new number is smaller than previous min.
               if (temp_results.min > temp_int)
                   temp_results.min = temp_int;

               // Average calculation
               number_of_values++;
               sum += temp_int;
               temp_results.avg = (sum / number_of_values);
           }
           else
           {
                std::cout << "Error in the input files, all rows are not valid." << std::endl;
           }
        } 
        
        // Print some warning output if the file could not be open read until EOF
        if (!input_file.eof()) {
           std::cout << "File could not be opened." << std::endl;
        }
        return temp_results;
    }

    // Start of processing
    void Run()
    {
        std::string wait_to_exit;
        std::string file_to_open = "scores.txt";
        Results student_results;

        // Start problem two
        std::cout << "############## START OF PROBLEM 02 ####################" << std::endl 
                  << "What is the name of the score file? (default: scores.txt)" << std::endl;

        // Get the name of the scores file from comand line
        getline(std::cin, file_to_open);

        if (file_to_open.empty()) {
            file_to_open = "scores.txt";
        }
       
        student_results = CalculateScores(file_to_open);

        std::cout << "Student results (min, max, avg): " << student_results.min << ", " << student_results.max << ", " << student_results.avg << std::endl << std::endl;

        std::cout << "############## END OF PROBLEM 02 ####################" << std::endl;
        std::getline(std::cin, wait_to_exit);
    }
}