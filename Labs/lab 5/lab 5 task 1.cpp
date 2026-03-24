#include <iostream>
#include <conio.h>

using namespace std;

struct LinkedList
{
    int m;
    LinkedList *next;
} *first = nullptr, *last = nullptr;

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

LinkedList *addLastEl(LinkedList *first, int data) {
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
    
}

int main()
{


    return 0;
}