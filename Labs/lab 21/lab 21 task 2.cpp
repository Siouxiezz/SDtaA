#include <iostream>
#include <vector>

using namespace std;

void printPlan(vector<vector<int>>& plan)
{
     int rows = plan.size(), cols = plan[0].size();
 
    cout << " | ";
    for (int j = 0; j < cols; j++)
    {
        cout << "S " << (j+1) << " | ";
    }
    cout << "\n";
 
    for (int i = 0; i < rows; i++) 
    {
        cout << "W " << (i+1) << " | ";
        for (int j = 0; j < cols; j++)
            cout << "  " << plan[i][j] << " | ";
        cout << "\n";
    }
}

int totalCost(const vector<vector<int>>& plan, const vector<vector<int>>& cost) 
{
    int total = 0;

    for (int i = 0; i < (int)plan.size(); i++)
    {
        for (int j = 0; j < (int)plan[0].size(); j++)
        {
            total += plan[i][j] * cost[i][j];
        }       
    } 

    return total;
}

vector<vector<int>> northwestCorner(vector<int> supply, vector<int> demand) 
{
    int m = supply.size(), n = demand.size();

    vector<vector<int>> plan(m, vector<int>(n, 0));
 
    int i = 0, j = 0;
    while (i < m && j < n) 
    {
        int qty = min(supply[i], demand[j]);
        plan[i][j] = qty;
        supply[i] -= qty;
        demand[j] -= qty;
 
        if (supply[i] == 0)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return plan;
}

vector<vector<int>> minimumCost(vector<int> supply, vector<int> demand,
                                const vector<vector<int>>& cost) 
{
    int m = supply.size(), n = demand.size();

    vector<vector<int>> plan(m, vector<int>(n, 0));
 
    for (int step = 0; step < m + n - 1; step++) 
    {
        int minCost = -1, minI = -1, minJ = -1;

        for (int i = 0; i < m; i++) 
        {
            if (supply[i] == 0) 
            { 
                continue;
            }
            for (int j = 0; j < n; j++) 
            {
                if (demand[j] == 0) 
                {
                    continue;
                }
                if (minCost == -1 || cost[i][j] < minCost) 
                {
                    minCost = cost[i][j];
                    minI = i; minJ = j;
                }
            }
        }
        if (minI == -1) 
        {
            break;
        }

        int qty = min(supply[minI], demand[minJ]);
        plan[minI][minJ] = qty;
        supply[minI] -= qty;
        demand[minJ] -= qty;
    }
    return plan;
}

int main()
{
    vector<vector<int>> cost = {
                                {8, 7, 2},
                                {1, 4, 3},
                                {5, 1, 6}
                                };

    vector<int> supply = {1500, 1900, 1600};
    vector<int> demand = {1800, 1200, 2000};

    int m = supply.size(), n = demand.size();

    cout << "Cost matrix:\n";
    cout << " | ";
    for (int j = 0; j < n; j++)
    {
        cout << " S" << (j+1) << " | ";
    }
    cout << " Supply\n";
 
    for (int i = 0; i < m; i++) 
    {
        cout << " W " << (i+1) << "  |";
        for (int j = 0; j < n; j++)
        {
            cout << "   " << cost[i][j] << "  |";
        }
        cout << "  " << supply[i] << "\n";
    }

    cout << "Demand \n";
    for (int j = 0; j < n; j++)
    {
        cout << " " << demand[j] << " |";
    }
    cout << "\n\n";

    cout << "NorthWest corner: \n";
    cout << "------------------------------------\n";

    auto plan1 = northwestCorner(supply, demand);
    printPlan(plan1);

    cout << "Total cost: " << totalCost(plan1, cost) << " | " << "\n";

    cout << "----------------------------------------------\n";

    cout << "Minimum cost method: \n";
    cout << "------------------------------------\n";

    auto plan2 = minimumCost(supply, demand, cost);
    printPlan(plan2);

    cout << "Total cost: " << totalCost(plan2, cost) << " | " << "\n";

    return 0;
}