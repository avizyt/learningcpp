#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPeople(const vector<int> &entry, const vector<int> &exit)
{
    int earliest = *min_element(entry.begin(), entry.end());
    int latest = *max_element(entry.begin(), entry.end());

    int maxCount = 0;
    int timeofMax = earliest;

    // check each possible time
    for (int t = earliest; t <= latest; t++)
    {
        int count = 0;
        for (size_t i = 0; i < entry.size(); i++)
        {
            if (entry[i] <= t && t < exit[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            timeofMax = t;
        }
    }
    cout << "Maximum count: " << maxCount << " at time " << timeofMax << endl;
    return maxCount;
}

int maxPeopleOptimized(const vector<int> &entry, const vector<int> &exit)
{
    vector<pair<int, int>> events;

    for (int time : entry)
    {
        events.emplace_back(time, 1);
    }

    for (int time : exit)
    {
        events.emplace_back(time, -1);
    }

    sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.first == b.first) return a.second < b.second;

        return a.first < b.first; });
}

int main()
{
    vector<int> entry = {1, 2, 9, 5, 5};
    vector<int> exit = {4, 6, 12, 8, 7};
    maxPeople(entry, exit);
    return 0;
}