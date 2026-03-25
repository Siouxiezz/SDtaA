#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int main() {
    int n;

    srand(time(NULL));

    cout << "Enter n: ";
    cin >> n;

    int a[10][10];
    int max = -10, maxRow = -1;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand()%21-5;
        }

    cout << "Your array: " << endl;
    }

    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && a[i][j] > max) 
            {
                max = a[i][j];
                    maxRow = i;
            }
        }
    }

    cout << "Result:\n";

    for (int i = 0; i < n; i++) {
        if (i == maxRow) continue;

        for (int j = 0; j < n; j++)
        {
            if (i != j)
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    getch();
}