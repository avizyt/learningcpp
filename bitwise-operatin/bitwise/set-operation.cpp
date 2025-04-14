#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);

    int z = x | y;
    cout << __builtin_popcount(z) << endl;

    for (int i = 0; i < 32; ++i)
    {
        if (z & (1 << i))
            cout << i << " ";
    }
}