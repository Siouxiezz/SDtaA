#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int* searchForEvenNumb(int arr[], int n, bool isEven, int &newSize)
{

    newSize = 0;

    for(int i = 0; i < n; i++)
    {
        if(isEven && arr[i] % 2 == 0)
        {
            newSize++;
        }
        if(!isEven && arr[i] % 2 != 0)
        {
            newSize ++;
        }
    }

    int* result = new int[newSize];
    int index = 0;

    for(int i = 0; i < n; i++)
    {
        if(isEven && arr[i] % 2 == 0)
        {
            result[index] = arr[i];
            index++;
        }
        if(!isEven && arr[i] % 2 != 0)
        {
            result[index] = arr[i];
            index++;
        }
    }

    return result;

}

void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((ascending && arr[j] > arr[j+1]) || (!ascending && arr[j] < arr[j+1]))
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    cout << "Enter n: ";

    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()% 21 - 5;
        cout << arr[i] << " ";
    }

    int eSize, oSize;

    int* even; 
    searchForEvenNumb(arr, n, true, eSize);
    
    int* odd; 
    searchForEvenNumb(arr, n, false, oSize);

    bubbleSort(even, eSize, true);
    bubbleSort(odd, oSize, false);

    for (int i = 0; i < eSize; i++)
    {
        arr[i] = even[i];
    }
    for (int i = 0; i < oSize; i++)
    {
        arr[eSize+i] = odd[i];
    }

    cout << "\nResult: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    getch(); 
    
    delete[] arr;
    delete[] even;
    delete[] odd;

    return 0;
}