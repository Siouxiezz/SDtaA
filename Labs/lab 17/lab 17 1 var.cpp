#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int group;
    int grades[4];
    double average;
};

double countAverage(Student students[], int n)
{
    double total = 0;

    for(int i = 0; i < n; i++)
    {
        double sum = 0;

        for(int j = 0; j < 4; j++)
        {
            sum += students[i].grades[j];
        }
        students[i].average = sum / 4.0;
        total += students[i].average;
    }

    return total / n;
}

void bubbleSort(Student students[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(students[j].average > students[j + 1].average)
            {
                swap(students[j], students[j + 1]);
            }
        }
    }

}

void insertionSort(Student students[], int n)
{
    for(int i = 1; i < n; i++)
    {
        Student key = students[i];
        int j = i - 1;
        while(j >= 0 && students[j].group < key.group)
        {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }
}

int binarySort(Student students[], int n, double target)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(students[mid].average == target)
        {
            return mid;
        }else if(students[mid].average < target)
        {
            left = mid + 1;
        }else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void printInfo(Student students[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Name: " << students[i].name << "\n";
        cout << "Group: " << students[i].group << "\n";
        cout << "Grades: ";
        for(int j = 0; j < 4; j++)
        {
            cout << students[i].grades[j] << " ";
        }
        cout << "\nAverage: " << students[i].average;
        cout << "\n=====================================================\n";
    }
}

void waitForEnter()
{
    cout << "\t\nTap enter to continue...\t";
        cin.get();
        system("cls");
}

int main()
{
  
    const int n = 6;

    Student students[n] = {
                          {"Roma", 144, {99, 95, 94, 97}, 0},
                          {"Masha", 143, {86, 80, 70, 91}, 0},
                          {"Sanya", 142, {83, 51, 65, 60}, 0},
                          {"Ivan", 143, {80, 75, 70, 51}, 0},
                          {"Denys", 146, {79, 74, 86, 90}, 0},
                          {"Nastia", 141, {98, 92, 90, 89}, 0}
                          };


    Student copy[n];

    countAverage(students, n);

    double target = 96.25;

    for(int i = 0; i < n; i++)
    {
        copy[i] = students[i];
    }

    cout << "Your array of students: \n";
    printInfo(students, n);

    waitForEnter();

    cout << "Array was sorted by bubble sort by average: \n";
    bubbleSort(students, n);

    printInfo(students, n);

    waitForEnter();

    cout << "Array was sorted by insertion sort: \n";
    insertionSort(copy, n);

    printInfo(copy, n);

    waitForEnter();    

    cout << "Array was sorted by bynary sort: \n";
    int index = binarySort(students, n, target);

    if(index == -1)
    {
        cout << "No students were found.\n";
    }
    else
    {
        cout << "Found: " << students[index].name << "\n"
             << "Group: " << students[index].group << "\n"
             << "Average: " << students[index].average << "\n";
    }

    cin.get();

    return 0; 
}