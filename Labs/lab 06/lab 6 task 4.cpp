#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Team
{
    string name, city;
    int points;

};

struct Queue
{
    Team data;
    Queue* next;
};

void push(Queue*& first, Queue*& last, Team dat)
{
    Queue* s = new Queue;
    s -> data = dat;
    s -> next = 0;
    
    if(!first)
    {
        first = last = s;
    }
    else
    {
        last->next = s;
        last = s;
    }
}

Team pop(Queue*& first, Queue*& last)
{
    Team empty;

    if(!first)
    {
        return empty;
    }

    Queue* s = first;
    Team value = s -> data;

    first = first -> next;

    if(!first)
    {
        last = 0;
    }

    delete s;
    return value;
}

Team front(Queue* first)
{
    if(!first)
    {
        Team empty;
        return empty;
    }

    return first -> data;
}

bool isEmpty(Queue* first)
{
    return first == 0;
}

int main()
{
    Queue* qFirst = 0, *qLast = 0;

    push(qFirst, qLast, {"Prometey", "Dnipro", 30});
    push(qFirst, qLast, {"Locomotive", "Kharkiv", 15});
    push(qFirst, qLast, {"Barkom-Kazhany", "Lviv", 17});

    Team best {"", "", -1};
    Team worst {"", "", 100};

    cout << "\tAll teams\n";

    while(!isEmpty(qFirst))
    {
        Team t = front(qFirst);

        cout << "Command: " << t.name 
             << " | City: " << t.city 
             << " | Points: " << t.points << endl;
        cout << "=====================================================\n";

        if (t.points > best.points) 
        {
            best = t;
        }
        if (t.points < worst.points) 
        {
            worst = t;
        }

         pop(qFirst, qLast);
    }

    cout << "\nBest team: " << best.name 
         << " (" << best.points << ")" << endl;
    cout << "Worst team: " << worst.name 
         << " (" << worst.points << ")" << endl;

    getch();
 
    return 0;
}