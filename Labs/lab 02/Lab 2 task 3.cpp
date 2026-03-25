#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int main() {

    const int n = 5;
    int a[n][n];
    srand(time(NULL));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        a[i][j] = rand()%31-10;
        }
    }

    int max = a[0][0], maxI = 0, maxJ = 0;

    cout << "Your array: ";
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max) {
                max = a[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        swap(a[0][j], a[maxI][j]);
    }

    cout << "\n Array after swapping rows:\n";
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
            cout << endl;
        }
    }


    cout << "\nArray after swapping columns:\n";
    for (int i = 0; i < n; i++)
    {
        swap(a[i][0], a[i][maxJ]);
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
            cout << endl;
        }
    }

    getch();

    return 0;
}