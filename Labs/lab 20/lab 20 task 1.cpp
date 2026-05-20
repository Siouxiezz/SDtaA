#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Backpack
{
    string name;
    double volume; //дм
    double calories; //ккалорії
    double ratio; //калорії/об'єм
};

void printProducts( vector<Backpack>& Backpacks)
{
    cout << "Backpacks: \n";
    cout << "------------------------------\n";
    cout << "Name | Volume | Energy | Efficensy\n";

    for(const auto& p : Backpacks)
    {
        cout << p.name << " | "
             << p.volume << " | "
             << p.calories << " | "
             << p.ratio << "\n";
    }
}

void solveKnapsack(vector<Backpack> Backpacks, double maxVolume, double maxWeight)
{
    sort(Backpacks.begin(), Backpacks.end(),
         [](const Backpack& a, const Backpack& b)
         {
             return a.ratio > b.ratio;
         });
 
    printProducts(Backpacks);
 
    double usedVolume = 0.0;
    double usedWeight = 0.0;
    double totalCalories = 0.0;
 
    double sugar  = 1.0;
    double milk   = 8.0 * sugar;
    double flour  = milk;
    double meat   = 2.0 * flour;  
 
    double volSugar = sugar  * 1.0;
    double volMilk  = milk   * 2.0;
    double volFlour = flour  * 1.5;
    double volMeat  = meat   * 1.0;
 
    usedVolume = volSugar + volMilk + volFlour + volMeat;
    usedWeight = sugar + milk + flour + meat;
 
    totalCalories = sugar  * 4000 + milk   * 5000 + flour  * 5000 + meat   * 1500;
 
    cout << "----------------------------------\n";

    cout << "\nBackpack | Quantity (kg) | Volume (dm) | Calories\n";

    cout << "Meat " << meat  << " | " << volMeat  << " | " << meat  * 1500 << "\n";
    cout << "Flour " << flour << " | " << volFlour << " | " << flour * 5000 << "\n";
    cout << "Milk " << milk  << " | " << volMilk  << " | " << milk  * 5000 << "\n";
    cout << "Sugar " << sugar << " | " << volSugar << " | " << sugar * 4000 << "\n";
    cout << "-----------------------------------------------\n";
    cout << "Overal: " << usedWeight << " kg " << usedVolume << " dm " << totalCalories << " kkcal\n";
 
}

int main()
{
    vector<Backpack> products = {
                                 {"Meat",  1.0, 1500, 1500.0 / 1.0},
                                 {"Flour",   1.5, 5000, 5000.0 / 1.5},
                                 {"Milk", 2.0, 5000, 5000.0 / 2.0},
                                 {"Sugar",  1.0, 4000, 4000.0 / 1.0}
                                 };

    double maxVolume = 45.0;
    double maxWeight = 35.0;
 
    solveKnapsack(products, maxVolume, maxWeight);       
             
    return 0;
}