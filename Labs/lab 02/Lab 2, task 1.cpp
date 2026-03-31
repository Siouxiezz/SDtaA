#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

void searchNewSize(int arr[], int n, bool isEven, int &newSize)
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
}

int* searchForEvenNumb(int arr[], int n, int &newSize, bool isEven)
{

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

void bubbleSort(int arr[], int &newSize, bool ascending) 
{   
    for (int i = 0; i < newSize - 1; i++)
    {
        for (int j = 0; j < newSize - i - 1; j++)
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

    int* even ; 
    searchNewSize(arr, n, true, eSize);
    even = searchForEvenNumb(arr, n, eSize, true);
    
    int* odd; 
    searchNewSize(arr, n, false, oSize);
    odd = searchForEvenNumb(arr, n, oSize, false);

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

    cout << "\n=======================";

    cout << "\nResult even: \n";
    for (int i = 0; i < eSize; i++)
    {
        cout << even[i] << " ";
    }

    cout << "\n=======================";

    cout << "\nResult odd: \n";
    for (int i = 0; i < oSize; i++)
    {
        cout << odd[i] << " ";
    }

    getch(); 
    
    delete[] arr;
    delete[] even;
    delete[] odd;

    return 0;
}