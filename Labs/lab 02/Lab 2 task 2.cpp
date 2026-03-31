#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{

    int n, i, a[20], X;
    int countDel = 0;
    srand(time(nullptr));

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter your X numb: ";
    cin >> X;

    cout << "Your matrix: ";
    for(i = 0; i < n;i++)
    {
        a[i] = rand()%11+0;
        cout << a[i] << " ";
    }
    
    cout << endl;

    for(i = 0;i < n;i++)
    {
        if(a[i] < X)
        {
            for(int j = i;j < n-1; j++)
                a[j] = a[j + 1];

            a[n-1] = 0;
            countDel++;
            i--;
            
        }
    }

    cout << "\nNew array: ";
    for(i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    getch();
    
    return 0;
}