#include <bits/stdc++.h>

using namespace std;

int recursiveDearangement(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    else
    {
        return (n - 1) * (recursiveDearangement(n - 2) + recursiveDearangement(n - 1));
    }
}

int main()
{
    int n = 3;
    cout << recursiveDearangement(n) << "\n";
}