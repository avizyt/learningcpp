#include <bits/stdc++.h>
using namespace std;

vector<int> getMax(vector<string> operations)
{
    stack<int> st;
    stack<int> maxVal;
    vector<int> result;
    for (string op : operations)
    {
        if (op[0] == '1')
        {
            int x = stoi(op.substr(2));
            st.push(x);
            if (maxVal.empty())
                maxVal.push(x);
            else
                maxVal.push(max(x, maxVal.top()));
        }
        else if (op[0] == '2')
        {
            if (!st.empty())
            {
                st.pop();
                maxVal.pop();
            }
        }
        else if (op[0] == '3')
        {
            if (!maxVal.empty())
            {
                result.push_back(maxVal.top());
            }
        }
    }
    return result;
}

int main()
{
    vector<string> ops = {
        "1 97", "2", "1 20", "2", "1 26", "1 20", "2",
        "3", "1 91", "3"};

    vector<int> res = getMax(ops);
    for (int x : res)
        cout << x << "\n";

    return 0;
}
