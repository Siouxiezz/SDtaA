#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Position
{
    string name;
    int A, B;
    int count;
};

int main()
{
    vector<Position> positions = {
                                  {"Sanitary", 1, 1, 7},
                                  {"Nurse", 6, 5, 10},
                                  {"Doctor", 8, 5, 10},
                                  {"Pharmacy manager", 9, 5, 1},
                                  {"Department head", 2, 1, 3},
                                  {"Chief doctor", 12, 5, 1},
                                  {"Head of Administration", 13, 5, 1},
                                  {"Head of Hospital", 3, 1, 1}  
                                 };

    const double TARGET = 380000.0;

    double bestSalary = 0.0;
    double bestFund = 0.0;

    for (int base = 1; base <= 10000; base++) 
    {
        double fund = 0;

        for (auto& p : positions) 
        {
            double K = (double)p.A / p.B;
            fund += base * K * p.count;
        }

        if(fund <= TARGET) 
        {
            bestSalary = base;
            bestFund   = fund;
        }
    }
               
    cout << "Optimal sanitary base salary: " << bestSalary << " UAH\n";
    cout << "Total salary fund: " << bestFund << " UAH\n";
    cout << "Target fund: " << TARGET << " UAH\n";

    cout << "Position" << " | " << "K=A/B" << " | " << "Salary" << " | " << "Count" << " | " << "Total" << "\n";
 
    double grandTotal = 0;
    for (auto& p : positions) 
    {
        double K = (double)p.A / p.B;
        double salary = bestSalary * K;
        double total  = salary * p.count;
        grandTotal += total;
 
        cout << p.name << " | " << K  << " | " << salary << " | " << p.count << " | " << total << "\n";
    }
 
    cout << "\nGrand total: " << grandTotal << " UAH\n";

    return 0;
}