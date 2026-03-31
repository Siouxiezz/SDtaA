#include <iostream>
// #include <conio.h>

using namespace std;

struct Mark
{
    int m;
    Mark *next;

} *first, *last = 0;

int main()
{
    Mark *c1 = new Mark;
    cin >> c1 -> m;
    c1 -> next = 0;
    first = c1;
    last = c1;

    Mark *c2 = new Mark;
    cin >> c2 -> m;
    c2 -> next = 0;
    last -> next = c2;
    last = c2;

    Mark *c = new Mark;
    cin >> c -> m;
    c -> next = first;
    first = c;

    Mark *c3 = new Mark;
    cin >> c3 -> m;
    c3 -> next = c2;
    c1 -> next = c3;

    Mark *q;
    // q = first;
    // while(q!=0)
    // {
    //     if(q -> m == 11)
    //     {
    //         c3 -> next = q -> next;
    //         q -> next = c3;
    //     }
    //     q = q -> next; 
    // } 

    // q = first;
    // first = first->next;
    // delete q;

    q = first;

    while(q!=0)
    {
        cout << q -> m << " ";
        q = q -> next;
    }

    cin.get();

    return 0;
}