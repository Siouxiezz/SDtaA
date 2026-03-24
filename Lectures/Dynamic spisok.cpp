#include <iostream>
#include <conio.h>

using namespace std;

struct Mark
{
    int m;
    Mark *next;

} *first, *last;

int main()
{
    Mark *c = new Mark;
    cin >> c -> m;
    c -> next = 0;
    first = c;
    last = c;

    Mark *c1 = new Mark;
    cin >> c1 -> m;
    c1 -> next = 0;
    last -> next = c1;
    last = c1;

    Mark *c2 = new Mark;
    cin >> c2 -> m;
    c2 -> next = first;
    first = c2;

    Mark *c3 = new Mark;
    cin >> c3 -> m;
    c3 -> next = 0;

    Mark *q;
    q = first;
    while(q!=0)
    {
        if(q -> m == 11)
        {
            c3 -> next = q -> next;
            q -> next = c3;
        }
        q = q -> next; 
    } 

    q = first;
    first = first -> next;
    q -> next = 0;

    q = first;

    while(q!=0)
    {
        cout << q -> m << " ";
        q = q -> next;
    }

    getch();
    return 0;
}