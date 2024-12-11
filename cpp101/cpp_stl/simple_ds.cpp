#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    vector<int> arr = {11, 22, 33, 44, 55};

    stack<int> s;
    queue<int> q;

    s.push(arr[0]);
    s.push(arr[1]);
    s.push(arr[2]);

    while (!arr.empty())
    {
        cout << arr.front() << endl;
    }
}