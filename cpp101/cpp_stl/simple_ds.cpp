#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    // vector<int> arr = {11, 22, 33, 44, 55};
    vector<vector<int>> mat = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}};

    // stack<int>
    //     s;
    // queue<int> q;

    // s.push(arr[0]);
    // s.push(arr[1]);
    // s.push(arr[2]);
    // cout << s.size() << endl;

    // // cout << s.pop() << " ";
    // // cout << s.pop() << " ";
    // // cout << s.pop() << " ";s

    int n = 3;
    mat.resize(n);

    for (auto arr : mat)
    {
        for (int item : arr)
        {
            cout << item << " ";
        }
    }
}