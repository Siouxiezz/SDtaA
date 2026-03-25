#include <iostream>
#include <stack>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
    int n;
    double value, limit, current, sum = 0;

    stack<double> st;
    stack<double> newStack;
    
    srand(time(NULL));

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter a number for the filtration: ";
    cin >> limit;

    for(int i = 0; i < n; i++)
    {
        value = -6 + (rand() % 171) / 10.0;
        st.push(value);
        cout << value << " ";
    }

    while(!st.empty())
    {
        current = st.top();
        st.pop();

        if(current >= limit)
        {
            newStack.push(current);
            sum += current;
        }
    }

    if(!newStack.empty())
    {
        cout << "\n Average numb of new stack is: " << sum / newStack.size() << endl;

        cout << "Numbers in new stack: \n";
        while(!newStack.empty())
        {
            cout << newStack.top() << " ";
            newStack.pop();
        }
    }

    getch();

    return 0;
}