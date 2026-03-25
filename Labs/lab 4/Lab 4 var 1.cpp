#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Student
{
    string Name;
    int Group;
    int SES[5];
};

float average(Student S)
{
    float sum = 0;
    for(int i = 0;i < 5; i++)
        {
            sum += S.SES[i];
        }

    return sum / 5.0;

}

void display(Student arr[], int n)
{
    for(int i = 0; i < n; i++){
    cout << arr[i].Name << " " 
         << arr[i].Group << " " 
         << average(arr[i]) << endl;
    }
}

void displayGoodStudents(Student arr[], int n)
{
    bool found = false;

    for(int i = 0; i < n; i++)
    {
        if(average(arr[i]) > 4.0)
        {
            cout << arr[i].Name << " " << arr[i].Group << " " << average(arr[i]) << endl;
            found = true;
        }
    }

    if(!found)
    {
        cout << "There are no students with grade higher than 4.0";
    }
}

bool isVowel(char c)
{
    string vowels("AEIOUYaeiouy");

    for(char v : vowels){
        if(v == c) 
        {
        return true;
        }
    }
    return false;
}

void displayVowelStudents(Student arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(isVowel(arr[i].Name[0]))
        {
            cout << arr[i].Name << " " << arr[i].Group << endl;
        }
    }
}

void sortStudents(Student arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for( int j = 0; j < n - i - 1; j++)
        {
            if(average(arr[j]) < average(arr[j + 1]))
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{

    int n;
    cout << "Enter students quantity: ";
    cin >> n;

    Student arr[100];

    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        cout << "\tStudent " << i+1;

        cout << "\nEnter name of this student: ";
        getline(cin, arr[i].Name);

        cout << "Enter group of this student (number): ";
        cin >> arr[i].Group;

        cout << "Enter 5 marks: ";
        for(int j = 0; j < 5; j++) {
            cin >> arr[i].SES[j];
        }

        cin.ignore();
    }

    cout << "\tStudents: \t\n";
    display(arr, n);

    cout << endl;

    cout << "\nStudents which mark higher that 4.0: \n";
    displayGoodStudents(arr, n);

    cout << endl;

    cout << "\nStudents which names starts with vowel: \n";
    displayVowelStudents(arr,n);

    cout << "\nStudents sorted, based on their average mark: \n";
    sortStudents(arr,n);
    display(arr, n);
    
    getch();

    return 0;
}