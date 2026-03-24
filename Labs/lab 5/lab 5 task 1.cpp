#include <iostream>
#include <conio.h>

using namespace std;

struct LinkedList
{
    int m;
    LinkedList *next;
} *first = 0, *last = 0;

LinkedList *addFirstEl(LinkedList *first, int data)
{
    LinkedList *c = new LinkedList;
    c -> m = data;
    c -> next = first;
    first = c;

    if (last == 0)
    {
        last = first;
    }
    return first;
}

LinkedList *addLastEl(LinkedList *first, int data) 
{
    LinkedList *c = new LinkedList;
    c->m = data;
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

LinkedList *addElAfterSmth(LinkedList *first, int data, int dataAfterAdd)
{
    LinkedList *q = first;
    while(q != nullptr && q->m != dataAfterAdd)
    {
        q = q->next;
    }

    if(q == 0)
    {
        cout << "List is empty\n";
        return first;
    }

    LinkedList *c = new LinkedList;
    c->m = data;
    c->next = q->next;
    q->next = c;
    return first;
}

void showList(LinkedList *first) 
{
    LinkedList *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {

        cout << q->m << " ";
        q = q->next;
    }
    cout << endl;
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

void deleteList(LinkedList *first) 
{
    if (first == 0) 
        return;

    while (first != 0) 
    {
        LinkedList *temp = first;
        first = first->next;
        delete temp;
    }
}

int main()
{
    showList(first);
    cout << endl;

    first = addFirstEl(first, 10);
    first = addLastEl(first, 30);
    first = addElAfterSmth(first, 20, 10);
    first = addElAfterSmth(first, 25, 10);

    cout << "Your list\n";
    showList(first);
    cout << endl;

    cout << "Average of this list: \n" << countAvgNumb(first) << endl;

    cout << "List after deleting first numb: \n";
    first = deleteFirstEvenNumber(first);
    showList(first);
    deleteList(first);

    getch();

    return 0;
}