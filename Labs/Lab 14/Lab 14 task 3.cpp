#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string name, group;
    double gpa;
};

void addStudent(vector<Student>& list, const string& name, const string& group, double gpa)
{
    list.push_back({name, group, gpa});
}

void sortByGpa(vector<Student>& list)
{
    int n = list.size();
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (list[j].gpa < list[j + 1].gpa) 
            {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

void findByGroup(const vector<Student>& list, const string& group)
{
    cout << "\nStudents from group " << group << ":\n";

    for (int i = 0; i < (int)list.size(); i++)
    {
        if (list[i].group == group)
        {
            cout << "  " << list[i].name << " | " << list[i].gpa << "\n";
        }
    }
}

void printInfo(vector<Student>& list)
{
    cout << "\n All students \n";
    for(auto& s : list)
    {
        cout << " " << s.name << " " << s.group << " " << s.gpa << endl;
    }
}

int main()
{
    vector<Student> students;

    addStudent(students, "Ivan", "144", 4.5);
    addStudent(students, "Roma", "142", 5.0);
    addStudent(students, "Denys", "144", 4.9);
    addStudent(students, "Masha", "142", 4.3);
    addStudent(students, "Sasha", "141", 3.8);

    sortByGpa(students);
    printInfo(students);

    findByGroup(students, "144");

    cin.get();

    return 0;
}