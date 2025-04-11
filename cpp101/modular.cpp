#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 10;
    int m = 7;
    long long x = 1;
    for (int i = 0; i <= n; ++i)
    {
        x = (x * i) % m;
    }

    cout << x % m << "\n";
}