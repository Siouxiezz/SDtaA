#include <iostream>
#include <conio.h>

using namespace std;

struct City
{
    string name;
    int distance;
    City *next;
} *first = 0, *last = 0;

City *addCity(City *first, string name, int dist)
{
    City *c = new City;
    c -> name = name;
    c -> distance = dist;
    c -> next = 0;

    if (first == 0)
    {
        first = c;
        last = c;
        return first;
    }

    last->next = c;
    last = c;

    return first;
} 

void showList(City *first) 
{
    City *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {

        cout << q->name << " " 
             << q->distance << "km ";
        q = q->next;
    }
    cout << endl;
}

void printFarthestCities(City *first)
{
    City *q = first;
    City *max1 = 0, *max2 = 0;

    if (first == 0)
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0)
    {
        if (max1 == 0 || q->distance > max1->distance)
        {
            max2 = max1;
            max1 = q;
        }
        else if (max2 == 0 || q->distance > max2->distance)
        {
            max2 = q;
        }

        q = q->next;
    }

    cout << "Farthest cities:\n";

    if (max1 != 0)
        cout << max1->name << " " << max1->distance << "km\n";

    if (max2 != 0)
        cout << max2->name << " " << max2->distance << "km\n";
        
}

void deleteList(City *first) 
{
    if (first == 0) 
        return;

    while (first != 0) 
    {
        City *temp = first;
        first = first->next;
        delete temp;
    }
}

int main()
{
    first = addCity(first, "Uzhhorod", 800);
    first = addCity(first, "Mariupol", 750);
    first = addCity(first, "Berlin", 1200);
    
    cout << "Cities list:\n";
    showList(first);

    cout << endl;
    printFarthestCities(first);

    deleteList(first);

    getch();
    return 0;
}