#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> arr;
    char a = '*';
    int l = 0;
    int s = 5, e = 10;
    // cin >> s >>e;

    while (s <= e)
    {
        arr.emplace_back(s);
        ++s;
    }
    while (l <= arr.size() - 1)
    {
        // cout << arr.at(l) << " ";
        cout << string(arr.at(l), a) << endl;
        ++l;
    }
}
