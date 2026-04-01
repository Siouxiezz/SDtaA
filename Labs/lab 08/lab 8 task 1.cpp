#include <iostream>
#include <string>

using namespace std;

struct Book
{
    string name;
    string author;
    int year;
    Book *next;
    Book *prev;
}*first = 0, *last = 0, *first2 = 0, *last2 = 0;

Book* addBook(Book *first, Book *&last, string nm, string a, int y)
{
    Book *q = new Book;
    q -> name = nm;
    q -> author = a;
    q -> year = y;
    q -> next = 0; 
    q -> prev = last;

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

Book* mergeLists(Book *first, Book *last, Book *first2)
{
    if (first == 0) 
    {
        return first2;
    }

    last -> next = first2;
    first2 -> prev = last;

    return first;
}

void showListForward(Book *first) 
{
    Book *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {
        cout << "Name: " << q -> name << " | "
             << "Author: " << q -> author << " | "
             << "year: " << q -> year << endl;
        q = q -> next;
    }
    cout << endl;
}

void showListBackwards(Book *last) 
{
    Book *q = last;

    while (q != 0) 
    {
        cout << "Name: " << q -> name << " | "
             << "Author: " << q -> author << " | "
             << "year: " << q -> year << endl;
        q = q -> prev;
    }
    cout << endl;
}

void showList(Book *first) 
{
    Book *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {

        cout << "Name: " << q -> name << " | "
             << "Author: " << q -> author << " | "
             << "Year: " << q -> year << endl;
        q = q -> next;
    }
    cout << endl;
}

void deleteList(Book *first) 
{
    if (first == 0)
    {
        return;
    }
    
    while (first != 0) 
    {
        Book *temp = first;
        first = first -> next;
        delete temp;
    }
}

int main()
{
    first= addBook(first, last, "Kobzar", "Taras Shevchenko", 1860);
    first = addBook(first, last, "Ababdb", "Michael Jackson", 2004);
    first = addBook(first, last, "ASJJSkk", "Me", 2026);

    first2 = addBook(first2, last2, "ASsss", "IVan", 2022);
    first2 = addBook(first2, last2, "Garry Potter", "I forgot", 2009);
    first2 = addBook(first2, last2, "Project Hail Marry", "Cool author", 2015);
    first2 = addBook(first2, last2, "Garry Potter", "I forgot", 2012);


    cout << "Your list 1: \n";
    showList(first);

    cout << "Your list 2: \n";
    showList(first2);

    cout << "\n=================================\n";

    cout << "Your first list forward: \n";
    showListForward(first);

    cout << "Your first list backward: \n";
    showListBackwards(last);

    cout << "\n=================================\n";

    cout << "Your second list forward: \n";
    showListForward(first2);

    cout << "Your second list backward: \n";
    showListBackwards(last2);

    first = mergeLists(first, last, first2);

    cout << "Your lists after merge: \n";
    showList(first);

    cin.get();

    deleteList(first);
    deleteList(first2);

    return 0;
}