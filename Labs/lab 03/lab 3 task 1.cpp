#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

struct Worker 
{
	string surnameAndInitials;
	string position;
	int yearOfAdmission;
	double salary;
};

int expirience(Worker w, int currYear)
{
	int yearOfAdmission, finalYear = 0;

		finalYear = currYear - w.yearOfAdmission;
		return finalYear;
}

double salaryAfterTax(Worker w)
{
	double tax;
	tax = 0.67;
	return w.salary * tax;
}


int main()
{
	Worker w[100];
	int n, i, currYear;

	cout << "Enter count of workers: ";
	cin >> n;

	cout << "Enter current year: ";
	cin >> currYear;

	for (i = 0; i < n; i++)
	{
		cout << "\nWorker num " << i + 1 << endl;

		cin.ignore();
		cout << "Enter surname and initials: ";
		getline(cin, w[i].surnameAndInitials);
		
		cout << "Enter position: ";
		cin >> w[i].position;
		
		cout << "Enter year of admission: ";
		cin >> w[i].yearOfAdmission;
		
		cout << "Enter worker's salary: ";
		cin >> w[i].salary;
	}

	cout << "\nWorker's info: \n";
	for (i = 0; i < n; i++)
	{
		cout << "==========================";
		cout << "\nWorker number: " << i + 1 << endl;
		cout << "Name: " << w[i].surnameAndInitials << endl;
		cout << "Position: " << w[i].position << endl;
		cout << "Expirience: " << expirience(w[i], currYear) << endl;
		cout << "Salary after tax: " << salaryAfterTax(w[i]) << endl;
	}

	getch();

	return 0;
}