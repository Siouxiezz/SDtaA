#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Activity
{
    int index;
    int start;
    int end;
};

void printActivities( vector<Activity>& activities)
{
    cout << "Activities: \n";
    cout << "------------------------------\n";
    cout << "Index | Start | End\n";

    for(const auto& p : activities)
    {
        cout << p.index << " | "
             << p.start << " | "
             << p.end << "\n";
    }
}

vector<Activity> selectActivities(vector<Activity> activities)
{
    sort(activities.begin(), activities.end(),
         [](const Activity& a, const Activity& b)
         {
             return a.end < b.end;
         });
 
    cout << "\nActivities were sorted by ending time:\n";
    printActivities(activities);
 
    vector<Activity> selected;
    int lastEnd = -1;
 
    for (const auto& a : activities)
    {
        if (a.start >= lastEnd)
        {
            selected.push_back(a);
            lastEnd = a.end;
        }
    }
 
    return selected;
}

int main()
{
    cout << "Max capasity of activities \n";
 
    int n;
    cout << "Enter quantity of activities: ";
    cin >> n;
 
    vector<Activity> activities(n);
 
    cout << "Enter start and end time of each activity:\n";
 
    for (int i = 0; i < n; i++)
    {
        activities[i].index = i + 1;
        cout << "Activity " << i + 1 << " (start, end): ";
        cin >> activities[i].start >> activities[i].end;
    }
 
    printActivities(activities);
 
    vector<Activity> result = selectActivities(activities);
 
    cout << "Index | Start | End\n";
    cout << "------------------------------\n";
 
    for (const auto& a : result)
    {
        cout << a.index << " | " << a.start << " | " << a.end << "\n";
    }
 
    cout << "------------------------------\n";
    cout << "Max quantity of activities: " << result.size() << "\n";
 
    return 0;
}
