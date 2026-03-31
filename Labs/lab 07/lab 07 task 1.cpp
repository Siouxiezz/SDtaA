#include <iostream>
#include <string>

using namespace std;

struct Temperature
{
    int m;
    Temperature *next;
}*first, *last, *first2, *last2;

Temperature* addTemp(Temperature *next, Temperature *&last, int value)
{
    Temperature *q = new Temperature;
    q -> m = value;
    q -> next = 0; 

    if (first == 0)
    {
        first = q;
        last = q;
        return first;
    }

    last -> next = q;
    last = q;

    return first;
}

Temperature* mergeLists(Temperature *first, Temperature *last, Temperature *first2)
{
    if (first == 0) 
    {
        return first2;
    }

    last -> next = first2;

    return first;
}

void findMinAndMax(Temperature *first)
{
    if (first == 0)
    {
        cout << "List is empty\n";
        return;
    }

    int min = first -> m, max = first -> m;
    Temperature *q = first;

    while (q != 0)
    {
        if (q -> m < min)
        {
            min = q -> m;
        }
        if(q -> m > max)
        {
            max = q -> m;
        }

        q = q -> next;
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

void showList(Temperature *first) 
{
    Temperature *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {

        cout << q -> m << " ";
        q = q -> next;
    }
    cout << endl;
}

void deleteList(Temperature *first) 
{
    if (first == 0)
    {
        return;
    }
    
    while (first != 0) 
    {
        Temperature *temp = first;
        first = first -> next;
        delete temp;
    }
}

int main()
{
    first= addTemp(first, last, 10);
    first = addTemp(first, last, 5);
    first = addTemp(first, last, 20);

    first2 = addTemp(first2, last2, 7);
    first2 = addTemp(first2, last2, 15);


    cout << "Your list 1: \n";
    showList(first);

    cout << "Your list 2: \n";
    showList(first2);

    first = mergeLists(first, last, first2);

    cout << "Your lists after merge: \n";
    showList(first);

    cout << "\n=================================\n";

    cout << "Min and max of your list: \n";
    findMinAndMax(first);

    cin.get();

    deleteList(first);

    return 0;
}