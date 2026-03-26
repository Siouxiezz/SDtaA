#include <iostream>
#include <cmath>
#include <ctime>
#include <conio.h>

using namespace std;

struct Queue
{
    double data;
    Queue* next;
};

void push(Queue*& first, Queue*& last, double dat)
{
    Queue* s = new Queue;
    s -> data = dat;
    s -> next = 0;
    
    if(!first)
    {
        first = last = s;
    }
    else
    {
        last->next = s;
        last = s;
    }
}

double pop(Queue*& first, Queue*& last)
{
    if(!first)
    {
        return 0;
    }

    Queue* s = first;
    double value = s -> data;

    first = first -> next;

    if(!first)
    {
        last = 0;
    }

    delete s;
    return value;
}

double front(Queue* first)
{
    if(!first)
    {
        return 0;
    }

    return first -> data;
}

bool isEmpty(Queue* first)
{
    return first == 0;
}

int main()
{
    double dobytok = 1.0;
    int count = 0, value;
    srand(time(0));

    Queue *qFirst = NULL, *qLast = NULL;
    Queue *newFirst = NULL, *newLast = NULL;

    cout << "\tYour queue\n";

    for(int i = 0; i < 10; i++) 
    {
        value = rand() % 20 + 1;
        push(qFirst, qLast, value);
        cout << value << " ";
    }

    while(!isEmpty(qFirst))
    {
        int x = front(qFirst);
        pop(qFirst,qLast);

        if(x % 2 == 0)
        {
            push(newFirst, newLast, x);
            dobytok *= x;
            count++;

            push(newFirst, newLast, 100);
            dobytok *= 100;
            count++;
        }
    }

    cout << "\n===================================";

    cout << "\n\tYour new queue\n";

    while(!isEmpty(newFirst))
    {
        cout << front(newFirst) << " ";
        pop(newFirst, newLast);
    }

    cout << "\n===================================";

    cout << "\nGeometric mean: " << pow(dobytok, 1.0/count) << endl;

    while(!isEmpty(qFirst))
    {
        pop(qFirst, qLast);
    }

    getch();

    return 0;
}