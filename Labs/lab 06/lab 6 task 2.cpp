#include <iostream>
#include <stack>
#include <string>
#include <conio.h>

using namespace std;

struct Music
{
    string container, name, author;
    float time;
    int quantity;
    float price;
};

int main()
{
    string searchArtist;
    double totalTime = 0, cassetteSum = 0;
    stack<Music> catalog;
    stack<Music> cassette;

    catalog.push({"Vinyl record", "Stairway to Heaven", "Led Zeppelin", 8.02, 9, 500.0});
    catalog.push({"Audio cassette", "Thriller", "Michael Jackson", 4.19, 9, 150.0});
    catalog.push({"Audio cassette", "Billie Jean", "Michael Jackson", 4.54, 1, 150.0});
    catalog.push({"Laser Disc", "Smell like Teen spirit", "Nirvana", 5.01, 1, 300.0});
    catalog.push({"Audio cassette", "Thriller", "Michael Jackson", 5.57, 1, 180.0});

    cout << "Enter artist: ";
    getline(cin, searchArtist);

    while(!catalog.empty())
    {
        Music m = catalog.top();
        catalog.pop();

        if(m.author == searchArtist)
        {
            totalTime += m.time;
        }
        
        if(m.container == "Audio cassette")
        {
            cassette.push(m);
            cassetteSum += m.price;
        }
    }

    cout << "Duration time " << searchArtist << ": " << totalTime << " min." << endl;
    if (!cassette.empty()) {
        cout << "Average sum of cassetes: " << cassetteSum / cassette.size() << "$" << endl;
    }

    getch();

    return 0;
}