#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;

    for (int i = 1; i <= 10; ++i)
    {
        st.push(i);
    }
    for (int i = 1; i <= 10; ++i)
    {
        q.push(i);
    }
    cout << "Size of Stack: " << st.size() << "\n";
    cout << "Size of Queue: " << q.size() << "\n";

    while (!st.empty())
    {

        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}