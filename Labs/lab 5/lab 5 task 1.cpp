#include <iostream>
#include <conio.h>

using namespace std;

struct LinkedList
{
    int m;
    LinkedList *next;
} *first, *last = 0;

LinkedList *addFirstEl(LinkedList *first, int data)
{
    LinkedList *c = new LinkedList;
    c -> m = data;
    c -> next = first;
    first = c;
    if (last == 0)
    {
        last = first;
        return first;
    }
}

LinkedList *addLastEl(LinkedList *first, int data) 
{
    LinkedList *c = new LinkedList;
    c->m = data;
    c->next = 0;
    last->next = c;
    last = c;
    if (first == 0) 
    {
        first = c;
        last = c;
        return first;
    }

    return first;
}

LinkedList *addElAfterSmth(LinkedList *first, int data, int dataAfterAdd)
{
    LinkedList *q = new LinkedList;
    while(q != 0 && q->m != dataAfterAdd)
    {
        q = q->next;
    }

    LinkedList *c = new LinkedList;
    c->m = data;
    c->next = q->next;
    q->next = c;
    return first;
}

LinkedList *deleteFirstEl(LinkedList *first) 
{
    LinkedList *q = first;
    first = first->next;

    if (first == 0) 
    {
        cout << "The list is empty";
    }

    delete q;
    return first;
}

LinkedList *delelteLastEl(LinkedList *first) 
{
    if (first == 0) 
    {
        cout << "List is empty";
    }

    LinkedList *q = first;

    while (q->next != last)
        q = q->next;

    delete last;
    last = q;
    last->next = 0;
    return first;
}

void showList(LinkedList *first) 
{
    LinkedList *q = first;

    while (q != 0) 
    {
        cout << q->m << " ";
        q = q->next;
    }
    cout << endl;

    if (q == 0) 
    {
        cout << "List is empty" << endl;
        return;
    }
}

double countAvgNumb(LinkedList *first)
{
    LinkedList *q = first;
    double sum = 0.0;
    int count = 0;

    while (q != 0)
    {
        sum += q->m;
        q = q->next;
        count++;
    }

    return sum / (double) count;
}

LinkedList *deleteFirstEvenNumber(LinkedList *first) 
{
    LinkedList *q = first;

    if (q->m % 2 == 0) 
    {
        LinkedList *temp = q->next;
        delete q;
        return temp;
    }

    while (q->next != 0 && q->next->m % 2 != 0) 
    {
        q = q->next;
    }

    if (q->next == 0) 
    {
        cout << "Even number is not finded" << endl;
        return first;
    }

    LinkedList *temp = q->next;
    q->next = temp->next;
    delete temp;
    return first;
}

int main()
{


    return 0;
}