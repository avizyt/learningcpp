#include <bits/stdc++.h>
using namespace std;

string isBalance(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            if (
                (ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')

            )
            {
                st.pop();
            }
            else
            {
                return "NO";
            }
        }
    }
    return st.empty() ? "YES" : "NO";
}

int main()
{
    vector<string> inputs = {
        "{[()]}",
        "{[(])}",
        "{{[[(())]]}}"};

    for (string s : inputs)
    {
        cout << isBalance(s) << endl;
    }

    return 0;
}
