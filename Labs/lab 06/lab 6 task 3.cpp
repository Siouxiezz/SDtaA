#include <iostream>
#include <queue>
#include <cmath>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    double dobytok = 1.0;
    int count = 0;

    queue<int> q;
    queue<int> newQ;

    cout << "Your queue: ";

    for(int i = 0; i < 5; i++) 
    {
        q.push(rand() % 20 - 1);
        cout << q.front() << " ";
        q.pop();
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x % 2 == 0)
        {
            newQ.push(x);
            dobytok *= x;
            count++;
        }

        newQ.push(100);
        dobytok *= x;
        count++;
    }

    cout << "Your new queue: ";

    for(int i = 0; i < 5; i++)
    {
        cout << newQ.front() << " ";
        newQ.pop();
    }

    cout << "\nGeometric mean: " << pow(dobytok, 1.0/count) << endl;

    while(!q.empty())
    {
        q.pop();
    }

    getch();

    return 0;
}