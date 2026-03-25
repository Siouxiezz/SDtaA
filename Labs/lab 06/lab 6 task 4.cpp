#include <iostream>
#include <queue>
#include <string>
#include <conio.h>

using namespace std;

struct Team
{
    string name, city;
    int points;

};

int main()
{
    queue<Team> bazoka;

    bazoka.push({"Prometey", "Dnipro", 30});
    bazoka.push({"Locomotive", "Kharkiv", 15});
    bazoka.push({"Barkom-Kazhany", "Lviv", 17});

    queue<Team> copy = bazoka;
    Team best {"", "", -1}, worst {"", "", 100};
    queue<Team> uniqueCities;

    cout << "\tAll teams\n";

    while(!copy.empty())
    {
        Team t = copy.front();

        cout << "Command: " << t.name 
             << " | City: " << t.city 
             << " | Points: " << t.points << endl;
        cout << "=====================================================\n";
        
        copy.pop();

        if (t.points > best.points) best = t;
        if (t.points < worst.points) worst = t;
    }

    cout << "Best team: " << best.name << " (" << best.points << ")" << endl;
    cout << "Worst team: " << worst.name << " (" << worst.points << ")" << endl;

    getch();
 
    return 0;
}