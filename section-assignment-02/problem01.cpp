// problem01.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace Problem01
{

    struct EmailMsg 
    {
        std::string to;
        std::string from;
        std::string message;
        std::string subject;
        int date;
        int time;
    };

    void readMessagesFromFile(std::vector<EmailMsg> & messages,
                              std::string filename)
    {
        std::ifstream input_file;
        std::string line;
        std::stringstream ss;
        std::string field;
        char delimeter = ',';
        
        // Open the file
        input_file.open(filename);
        
        while (input_file.good())
        {
            getline(input_file, line);
            ss << line;

            while (std::getline(ss, field, delimeter))
            {
                std::cout << field << std::endl;
            }

        }

        // Print some warning output if the file could not be open read until EOF
        if (!input_file.eof()) {
            std::cout << "Something went wrong when reading the file. Either the file could not be found or is corrupt so it can not be fully read until end of file." << std::endl << std::endl;
        }
    }

    void removeSpam(std::vector<EmailMsg> & messages)
    {
        for (size_t i = 0; i < messages.size(); ++i)
        {
            std::cout << i << std::endl;
        }
    }

    // Start of processing
    void Run()
    {
        std::string wait_to_exit;
        std::string file_to_open = "scores.txt";
        std::vector<EmailMsg> messages;

        // Start problem one 
        std::cout << "############## START OF PROBLEM 01 ####################" << std::endl
            << "What is the name of the file to read? (default: email_addresses.csv)" << std::endl;

        // Get the name of the scores file from comand line
        getline(std::cin, file_to_open);

        if (file_to_open.empty()) {
            file_to_open = "email_addresses.csv";
        }

        readMessagesFromFile(messages, file_to_open); 
        removeSpam(messages);

        std::cout << "############### END OF PROBLEM 01 #####################" << std::endl;
        std::getline(std::cin, wait_to_exit);
    }
}