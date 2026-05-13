#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string key = "phqgiumeaylnofdxjkrcvstzwb";

string subtitutionCode(string text, string fromAlpha, string toAlpha)
{
    string result = "";

    for (char c : text)
    {
        char lower = tolower(c);
        size_t pos = fromAlpha.find(lower);

        if (pos != string::npos)
        {
            char replaced = toAlpha[pos];

            if (isupper(c))
            {
                result += (char)toupper(replaced);
            }
            else
            {
                result += replaced;
            }
        }
        else
        {
            result += c;
        }
    }

    return result;
}

int main()
{
    int choice, action;
    string text;

    cout << "\t Substitution cipher \n";
    cout << "Alphabet: " << alphabet << "\n";
    cout << "Key: " << key << "\n";

    cout << "\n 1. Enter text manually\n" << "2. Read from file (input.txt)\n" <<  "Choice: ";

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
    }
    else
    {
        cout << "Enter text: ";
        getline(cin, text);
    }

    cout << "Choose the action: \n" << "1.Encrypt\n" << "2.Descrypt\n" << "Choice: ";
    cin >> action;

    if (action == 1)
    {
        cout << "Encrypted text: "
             << subtitutionCode(text, alphabet, key)
             << "\n";
    }
    else if (action == 2)
    {
        cout << "Decrypted text: "
             << subtitutionCode(text, key, alphabet)
             << "\n";
    }

    return 0;
}