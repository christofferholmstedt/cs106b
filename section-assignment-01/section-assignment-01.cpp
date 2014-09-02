// section-assignment-01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string CensorString(string text, string remove) {
    string return_string = "";

    bool found_character = false;

    for (char& c : text)
    {
        for (char& r : remove)
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

int _tmain(int argc, _TCHAR* argv[])
{
	string input_text;
    string output_text;
	string remove_text;
	string wait_to_exit;

	cout << "Type your text:" << endl;
	getline(cin, input_text);

    cout << "Type in your text to be removed" << endl;
    getline(cin, remove_text);

    output_text = CensorString(input_text, remove_text);

    cout << "#####" << endl <<
         "Output text: " << output_text << endl;

    getline(cin, wait_to_exit);
	return 0;
}
