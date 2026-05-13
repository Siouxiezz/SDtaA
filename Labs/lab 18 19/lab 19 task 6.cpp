#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

map<char, string> morseCode = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},
    {'D', "-.."},   {'E', "."},     {'F', "..-."},
    {'G', "--."},   {'H', "...."},  {'I', ".."},
    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},
    {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},
    {'S', "..."},   {'T', "-"},     {'U', "..-"},
    {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},
    {'1', ".----"},{'2', "..---"}, {'3', "...--"},
    {'4', "....-"},{'5', "....."}, {'6', "-...."},
    {'7', "--..."},{'8', "---.."},{'9', "----."},
    {'0', "-----"},
    {' ', "/"}
};

string encryptMorse(string text)
{
    string result = "";

    for (char c : text)
    {
        c = (char)toupper(c);

        if (morseCode.find(c) != morseCode.end())
        {
            result += morseCode[c] + " ";
        }
    }

    return result;
}

string decryptMorse(string code)
{
    string result = "";
    string current = "";

    map<string, char> reverseMorse;

    for (auto pair : morseCode)
    {
        reverseMorse[pair.second] = pair.first;
    }

    for (char c : code)
    {
        if (c != ' ')
        {
            current += c;
        }
        else
        {
            if (reverseMorse.find(current) != reverseMorse.end())
            {
                result += reverseMorse[current];
            }

            current = "";
        }
    }

    if (!current.empty())
    {
        if (reverseMorse.find(current) != reverseMorse.end())
        {
            result += reverseMorse[current];
        }
    }

    return result;
}

int main()
{
    int choice, action;
    string text;

    cout << "\t Morse Code Program\n";

    cout << "\n1. Enter text manually\n"
         << "2. Read from file (input.txt)\n"
         << "Choice: ";

    cin >> choice;
    cin.ignore();

    if (choice == 2)
    {
        ifstream file("D:/AtaP/SDtaA/Labs/lab 18 19/input.txt");

        if (!file.is_open())
        {
            cerr << "File not found!\n";
            return 1;
        }

        getline(file, text);

        file.close();
    }
    else
    {
        cout << "Enter text: ";
        getline(cin, text);
    }

    cout << "\nChoose action:\n"
         << "1. Encrypt to Morse\n"
         << "2. Decrypt Morse\n"
         << "Choice: ";

    cin >> action;
    cin.ignore();

    if (action == 1)
    {
        string encrypted = encryptMorse(text);

        cout << "\nEncrypted text:\n"
             << encrypted << "\n";

        ofstream outFile("output.txt");
        outFile << encrypted;
        outFile.close();

        cout << "Saved to output.txt\n";
    }
    else if (action == 2)
    {
        string decrypted = decryptMorse(text);

        cout << "\nDecrypted text:\n"
             << decrypted << "\n";

        ofstream outFile("output.txt");
        outFile << decrypted;
        outFile.close();

        cout << "Saved to output.txt\n";
    }
    else
    {
        cout << "Invalid choice!\n";
    }

    return 0;
}