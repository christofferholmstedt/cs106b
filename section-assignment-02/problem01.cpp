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
        std::stringstream stringStreamTemp;
        std::string field;
        char delimeter = ',';
        
        // Open the file
        input_file.open(filename);
        
        while (getline(input_file, line) && input_file.good())
        {
            stringStreamTemp << line;

            int k = 0;
            EmailMsg tempStruct;
            while (getline(stringStreamTemp, field, delimeter))
            {
                switch (k)
                {
                case 0:
                    tempStruct.to = field;
                    break;
                case 1:
                    tempStruct.from = field;
                    break;
                case 2:
                    tempStruct.message = field;
                    break;
                case 3:
                    tempStruct.subject = field;
                    break;
                case 4:
                    tempStruct.date = atoi(field.c_str());
                    break;
                case 5:
                    tempStruct.time = atoi(field.c_str());
                    break;
                }
                k++;
            }
            if (!tempStruct.subject.empty())
            {
                messages.push_back(tempStruct);
            }
            stringStreamTemp.clear();
        }

        // Print some warning output if the file could not be open read until EOF
        if (!input_file.eof()) {
            std::cout << "Something went wrong when reading the file. Either the file could not be found or is corrupt so it can not be fully read until end of file." << std::endl << std::endl;
        }
    }

    void removeSpam(std::vector<EmailMsg> & messages)
    {
        std::vector<int> spamEmailsNo;
        std::vector<EmailMsg> tempMessages; 

        for (size_t i = 0; i < messages.size(); ++i)
        {
            std::size_t temp = messages[i].subject.find("SPAM");
            if (temp != std::string::npos)
            {
                spamEmailsNo.push_back(i);
            }
        }
         
        for (auto i = spamEmailsNo.rbegin(); i != spamEmailsNo.rend(); ++i)
        {
            messages.erase(messages.begin() + *i);
        }
    }

    // Loop through and print all emails
    void printEmails(std::vector<EmailMsg> & messages)
    {
        std::cout << "###### ALL EMAILS LISTED BELOW ######" << std::endl;
        for (size_t i = 0; i < messages.size(); ++i)
        {
            std::cout << messages[i].to << ", " <<
                         messages[i].from << ", " <<
                         messages[i].subject << ", " <<
                         //messages[i].message << ", " <<
                         //messages[i].date << ", " <<
                         //messages[i].time << ", " <<
                         std::endl;
        }
        std::cout << "###### ALL EMAILS LISTED ABOVE ######" << std::endl;
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
        printEmails(messages);
        removeSpam(messages);
        printEmails(messages);

        std::cout << "############### END OF PROBLEM 01 #####################" << std::endl;
        std::getline(std::cin, wait_to_exit);
    }
}