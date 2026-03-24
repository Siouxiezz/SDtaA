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
    c->name = name;
    c->distance = dist;
    c->next = 0;

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

int main()
{

    

    return 0;
}