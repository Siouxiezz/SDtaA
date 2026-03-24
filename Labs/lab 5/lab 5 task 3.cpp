#include <iostream>
#include <conio.h>

using namespace std;

struct Car
{
    string name;
    int year;
    int price;
    Car *next;
} *first = 0, *last = 0;

Car *createCar() 
{
    auto c = new Car;

    cout << "enter name: ";
    cin >> c -> name;
    cout << "enter year of create: ";
    cin >> c -> year;
    cout << "enter price: ";
    cin >> c -> price;

    c->next = 0;

    return c;
}

void showCar(Car const *car) 
{
    cout << "Name: " << car -> name << " | Year: " 
         << car -> year << " | Price: " 
         << car -> price << endl;
}

void showList(Car *first) 
{
    Car *q = first;

    if (q == 0) 
    {
        cout << "List is empty" << endl;
        return;
    }

    while (q != 0) 
    {
        showCar(q);
        q = q->next;
    }

    cout << endl;
}



int main()
{


    return 0;
}