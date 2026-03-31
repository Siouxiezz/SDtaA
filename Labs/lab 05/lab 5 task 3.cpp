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

Car *createCar(Car *first) 
{
    Car *c = new Car;

    cout << "Enter name of the car: ";
    cin >> c -> name;
    cout << "Enter year of creation: ";
    cin >> c -> year;
    cout << "Enter price: ";
    cin >> c -> price;

    c -> next = 0;

    if (first == 0)
    {
        first = c;
        last = c;
        return first;
    }

    last -> next = c;
    last = c;

    return first;
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

void printCars(Car *first)
{
    int currentYear;
    Car *q = first;

    if (q == 0)
    {
        cout << "List is empty\n";
        return;
    }

    cout << "Enter current year: ";
    cin >> currentYear;

    cout << "Cars older than 10 years and cheaper than 5000$: \n";

    while (q != 0)
    {
        if ((currentYear - q -> year > 10) && q -> price < 5000)
        {
            cout << q -> name << " "
                 << q -> year << " "
                 << q -> price << endl;
        }
        q = q -> next;
    }
}

void deleteCars(Car *first)
{
    if (first == 0)
    {
        return;
    }
    
    while (first != 0)
    {
        Car *temp = first;
        first = first -> next;
        delete temp;
    }
}

int main()
{
    first = createCar(first);
    first = createCar(first);
    first = createCar(first);

    cout << "Cars list:\n";
    showList(first);

    cout << endl;
    printCars(first);

    deleteCars(first);

    getch();

    return 0;
}