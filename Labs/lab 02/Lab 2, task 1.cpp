#include <iostream>
#include <conio.h>

using namespace std;

void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((ascending && arr[j] > arr[j+1]))
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int* even = new int[n];
    int* odd = new int[n];
    int e = 0, o = 0;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] % 2 == 0)
        {
            even[e++] = arr[i];
        }else
        {
            odd[o++] = arr[i];
        }
    }

    bubbleSort(even, e, true);
    bubbleSort(odd, o, false);

    for (int i = 0; i < e; i++)
    {
        arr[i] = even[i];
    }
    for (int i = 0; i < o; i++)
    {
        arr[e+i] = odd[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    getch(); 

    return 0;
}