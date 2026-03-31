#include <iostream>
#include <string>

using namespace std;

struct Worker
{
    string name;
    int department;
    int salary;
    Worker *next;
    Worker *prev;
}*first = 0, *last = 0;

Worker* addWorker(Worker *first, Worker *&last, string n, int d, int s)
{
    Worker *q = new Worker;
    q -> name = n;
    q -> department = d;
    q -> salary = s;
    q -> next = 0;
    q -> prev = last;

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

double countAverage(Worker *first)
{
    int sum = 0, count = 0;

    Worker *q = first;

    while (q != 0)
    {
        sum += q -> salary;
        count++;
        q = q -> next;
    }

    return (double)sum / count;
}

void separateList(Worker *first, Worker *&firstHighSal, Worker *&lastHighSal, Worker *&firstLowSal, Worker *&lastLowSal)
{
    double avg = countAverage(first);

    Worker *q = first;

    while (q != 0)
    {
        if (q -> salary > avg)
        {
            firstHighSal = addWorker(firstHighSal, lastHighSal, q -> name, q -> department, q -> salary);
        }
        
        else
        {
            firstLowSal = addWorker(firstLowSal, lastLowSal, q -> name, q -> department, q -> salary);
        }

        q = q -> next;
    }
}

void showListForward(Worker *first) 
{
    Worker *q = first;

    if (q == 0) 
    {
        cout << "List is empty\n";
        return;
    }

    while (q != 0) 
    {
        cout << "Name: " << q -> name << " | "
                          << "Department: " << q -> department << " | "
                          << "Salary: " << q -> salary << endl;
        q = q -> next;
    }
    cout << endl;
}

void showListBackwards(Worker *last) 
{
    Worker *q = last;

    while (q != 0) 
    {
        cout << "Name: " << q -> name << " | " 
             << "Department: " << q -> department << " | "
             << "Salary: " << q -> salary << endl;
        q = q -> prev;
    }
    cout << endl;
}

void deleteList(Worker *first) 
{
    if (first == 0)
    {
        return;
    }
    
    while (first != 0) 
    {
        Worker *temp = first;
        first = first -> next;
        delete temp;
    }
}

int main()
{
    Worker *firstHighSal = 0, *lastHighSal = 0;
    Worker *firstLowSal = 0, *lastLowSal = 0;

    first = addWorker(first, last, "Ivan", 1, 20000);
    first = addWorker(first, last, "Masha", 1, 25000);
    first = addWorker(first, last, "Denys", 1, 23000);
    first = addWorker(first, last, "Roma", 2, 3000);
    first = addWorker(first, last, "Sanya", 1, 50000);

    cout << "Your list forward: \n";
    showListForward(first);

    cout << "Your list backward: \n";
    showListBackwards(last);

    cout << "\n=================================\n";
    
    separateList(first, firstHighSal, lastHighSal, firstLowSal, lastLowSal);

    cout << "Your lists after separation. High salary: \n";
    showListForward(firstHighSal);

    cout << "Your lists after separation. Low salary: \n";
    showListForward(firstLowSal);

    cout << "=================================\n";

    cout << "Your high salary list forward: \n";
    showListForward(firstHighSal);

    cout << "Your high salary list backward: \n";
    showListBackwards(lastHighSal);

    cout << "=================================\n";

    cout << "Your low salary list forward: \n";
    showListForward(firstLowSal);

    cout << "Your low salary list backward: \n";
    showListBackwards(lastLowSal);


    firstHighSal = addWorker(firstHighSal, lastHighSal, "Igor", 1, 34000);

    cout << "Your new high salary list forward: \n";
    showListForward(firstHighSal);

    cin.get();

    deleteList(first);
    deleteList(firstHighSal);
    deleteList(firstLowSal);
    return 0;
}