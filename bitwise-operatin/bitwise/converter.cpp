#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 39;
    int b = 0;
    cout << format("a is {:b}", a) << endl;

    for (int i = 0; i <= 2; ++i)
    {
        a = a ^ (1 << i);
        cout << format("b is {:b}", a) << "\n";
        b = a;
    }
    cout << format("Final b: {} and Bin is {:b}", b, b) << "\n";
}