#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 282;
    cout << "Binary Repr of x: " << format("{:b}", a) << endl;

    int x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);

    cout << __builtin_popcount(x) << endl;

    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
            cout << i << " ";
    }
}