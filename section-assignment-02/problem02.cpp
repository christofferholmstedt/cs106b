// problem02.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

namespace problem02 
{
    void reverseQueue(std::queue<int> & q)
    {
        if (q.empty())
            return;
        int tempInt = q.front();
        q.pop();
        reverseQueue(q);
        q.push(tempInt);
    }
    
    bool isDigit(const std::string &str)
    {
        return str.find_first_not_of("0123456789") == std::string::npos;
    }

    void parseStringToInts(const std::string &text, char delim, std::queue<int> & q)
    {
        std::stringstream ss(text);
        std::string item;
        
        while (std::getline(ss, item, delim)) {
            if (!item.empty() && isDigit(item))
                q.push(atoi(item.c_str()));
        }
    }

    void printQueue(std::queue<int> & q)
    {
        std::cout << "###### The Queue ######" << std::endl;

        for (std::queue<int> dump = q; !dump.empty(); dump.pop())
             std::cout << dump.front() << '\n';

        std::cout << "###### End The Queue ######" << std::endl;
    }

    // Start of processing
    void run()
    {
        std::string waitToExit;
        std::string originalText;
        std::string inputText;
        std::queue<int> queueOfInts;
        std::vector<std::string> inputNumbersAsStrings;

        // Start problem one 
        std::cout << "############## START OF PROBLEM 02 ####################" << std::endl << 
                     "Type a series of numbers seperated with space?" << std::endl;

        std::getline(std::cin, originalText);
        inputText = originalText;

        parseStringToInts(inputText, ' ', queueOfInts);
        printQueue(queueOfInts);
        reverseQueue(queueOfInts);
        printQueue(queueOfInts);

        std::cout << "############### END OF PROBLEM 02 #####################" << std::endl;
        std::getline(std::cin, waitToExit);
    }
}