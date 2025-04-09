#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    int c = n - 1;
    while (c >= 0)
    {
        cout << arr.at(c) << " ";
        --c;
    }
    // for (int x : arr)
    // {

    //     cout << x << " ";
    // }
}