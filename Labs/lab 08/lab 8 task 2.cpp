#include <iostream>
#include <string>

using namespace std;

struct Bus
{
    int numbBus;
    string destination;
    int countPassengers;
    Bus *next;
}*first = 0, *last = 0, *first2 = 0, *last2 = 0;

Bus* addBus(Bus *&first, Bus *&last, int nB, string d, int cP)
{
    Bus *q = new Bus;
    q -> numbBus = nB;
    q -> destination = d;
    q -> countPassengers = cP;
    q -> next = 0;

    if (first == 0)
    {
        first = q;
        last = q;
        return first;
    }

    last -> next = q;
    last = q;

    return first;
}

Bus* mergeLists(Bus *&first, Bus *&last, Bus *&first2)
{
    if (first == 0) 
    {
        return first2;
    }

    last -> next = first2;

    return first;
}

void showList(Bus *first) 
{
    Bus *q = first;

    if (q == 0) 
    {
        cout << "Queue is empty\n";
        return;
    }

    while (q != 0) 
    {

        cout << "Bus number: " << q -> numbBus << " | "
             << "Destination: " << q -> destination << " | "
             << "Count passengers: " << q -> countPassengers << endl;
        q = q -> next;
    }
    cout << endl;
}

void showPassengers(Bus *first, int minPass)
{
    Bus *q = first;

    if (q == 0)
    {
        cout << "Queue is empty\n";
        return;
    }

    bool found = false;

    while (q != 0)
    {
        if (q -> countPassengers > minPass)
        {
            cout << "Route: " << q -> numbBus << " | "
                 << "Destination: " << q -> destination << " | "
                 << "Passengers: " << q -> countPassengers << endl;
            found = true;
        }
        q = q -> next;
    }

    if (!found)
    {
        cout << "No routes found with passengers > " << minPass << endl;
    }
    cout << endl;
}

Bus* deQueue(Bus *&first, Bus *&last)
{
    if (first == 0)
    {
        cout << "Queue is empty! \n";
        return 0;
    }

    cout << "Removing route: " << first -> numbBus
         << " | Destination: " << first -> destination
         << " | Passengers: " << first -> countPassengers << endl;

    if (first != 0)
    {
        Bus *temp = first;
        first = first -> next;
        delete temp;
    }

    return first;
}

void deleteList(Bus *first) 
{
    if (first == 0)
    {
        return;
    }
    
    while (first != 0) 
    {
        Bus *temp = first;
        first = first -> next;
        delete temp;
    }
}

int main()
{
    int nimPassengers = 0;
    
    first = addBus(first, last, 101, "Lviv", 45);
    first = addBus(first, last, 202, "Kyiv", 12);
    first = addBus(first, last, 303, "Odesa", 78);

    first2 = addBus(first2, last2, 404, "Kharkiv", 30);
    first2 = addBus(first2, last2, 505, "Dnipro", 5);
    first2 = addBus(first2, last2, 606, "Zaporizhzhia", 60);


    cout << "Enter min. count of passengers: ";
    cin >> nimPassengers;

    cout << "Queue 1:\n";
    showList(first);

    cout << "Queue 2:\n";
    showList(first2);

    cout << "\n=================================\n";

    cout << "Your merged queue: \n";
    first = mergeLists(first, last, first2);
    showList(first);

    cout << "\n=================================\n";

    cout << "Your queue with min count of passengers:\n";
    showPassengers(first, nimPassengers);

    deQueue(first, last);

    deleteList(first);

    cin.get();

    return 0;
}