#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> countFrequency(string line)
{
    map<char, int> frequency;

    for(char c : line)
    {
        frequency[c]++;
    }

    return frequency;
}

void printCount(map<char, int>& frequency)
{
    cout << "\nSymbol and Count\n";

    for(const auto& [ch, count] : frequency)
    {
        cout << " " << ch << " | " << count << endl;
    }
}

char countMostFreqChar(map<char, int>& frequency)
{
    char mostFreq = 0;
    int maxChar = 0;

    for(auto& [ch, count] : frequency)
    {
        if(count > maxChar)
        {
            maxChar = count;
            mostFreq = ch;
        }
    }

    return mostFreq;
}

int main()
{
    string line;

    cout << "Enter your sentence: ";
    getline(cin, line);

    auto frequency = countFrequency(line);
    printCount(frequency);

    auto most = countMostFreqChar(frequency);
    cout << "\nThe most common symbol: " << most << endl;
   


    cin.get();

    return 0;
}