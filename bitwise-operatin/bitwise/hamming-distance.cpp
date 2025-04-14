/*
The Hamming distance hamming(a,b) between two trings a and b
of equal length is the number of positions where the strings differ.
*/

#include <bits/stdc++.h>

using namespace std;

int hammingDist(string a, string b)
{
    int k = a.size();
    int d = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] != b[i])
            d++;
    }
    return d;
}

int hamming(int a, int b)
{
    int xorRe = a ^ b;
    int count = 0;

    while (xorRe)
    {
        count += xorRe & 1;
        xorRe >>= 1;
    }
    return count;
}

int hammingDistBuiltin(int a, int b)
{
    return __builtin_popcount(a ^ b);
}

int main()
{

    int a = 5;
    int b = 10;
    cout << hamming(a, b) << endl;

    string x = "01101";
    string y = "11001";
    cout << hammingDist(x, y) << endl;

    cout << hammingDistBuiltin(a, b);
}