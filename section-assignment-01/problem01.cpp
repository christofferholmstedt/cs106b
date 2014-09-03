// section_assignment1_problem1.cpp
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void CensorStringTwo(string & text, string remove) {

    // Solution from Handouts. January 14, 2008
    for(int i = 0; i < remove.length(); i++)
    {
        int pos = 0;
        while ((pos = text.find(remove[i], pos)) != string::npos)
        {
            text.replace(pos, 1, ""); // replace char with empty string
        }
    }
}

string CensorStringOne(string text, string remove) {
    string return_string = "";

    bool found_character = false;

    for (char & c : text)
    {
        for (char & r : remove)
        {
            if (c == r) {
                found_character = true;
            }
        }

        if (!found_character)
        {
            return_string += c;
        }
        else
        {
            found_character = false;
        }
    }
    return return_string;
}

void Run_Problem01()
{
    string original_text;
	string input_text;
    string output_text;
	string remove_text;
	string wait_to_exit;

	cout << "Type your text:" << endl;
	getline(cin, original_text);
    input_text = original_text;

    cout << "Type in your text to be removed" << endl;
    getline(cin, remove_text);

    output_text = CensorStringOne(input_text, remove_text);
    CensorStringTwo(input_text, remove_text);

    cout << "#####" << endl
         << "Original text: " << original_text << endl
         << "Input text: " << input_text << endl
         << "Output text: " << output_text << endl;

    getline(cin, wait_to_exit);
}