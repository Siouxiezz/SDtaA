#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Stack
{
    double value;
    Stack* next;
};

void push(Stack*& first, double val)
{
    Stack* s = new Stack;
    s -> value = val;
    s -> next = first;
    first = s;
}

double pop(Stack*& first)
{
    if(!first)
    {
        return 0;
    }

    Stack* s = first;
    double value = s -> value;
    first = first -> next;

    delete s;
    return value;
}

double top(Stack* first)
{
    if(!first)
    {
        return 0;
    }

    return first -> value;
}

int size(Stack* first)
{
    int count = 0;

    while(first)
    {
        count++;
        first = first -> next;
    }

    return count;
}

int main()
{
    int n;
    double value, limit, current, sum = 0;
    srand(time(NULL));

    Stack* st = 0;
    Stack* newSt = 0;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter a number for the filtration: ";
    cin >> limit;

    for(int i = 0; i < n; i++)
    {
        value = -6 + (rand() % 171) / 10.0;
        push(st, value);
        cout << value << " ";
    }

    while(st != 0)
    {
        current = top(st);
        pop(st);

        if(current >= limit)
        {
            push(newSt, current);
            sum += current;
        }
    }

    if(newSt != 0)
    {
        cout << "\n Average numb of new stack is: " << sum / size(newSt) << endl;

        cout << "Numbers in new stack: \n";
        while(newSt != 0)
        {
            cout << top(newSt) << " ";
            pop(newSt);
        }
    }

    getch();

    return 0;
}