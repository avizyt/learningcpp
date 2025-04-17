#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 34;

    cout << "Binary Repr of x: " << format("{:b}", x) << endl;

    int y = x | (1 << 3);
    cout << "Binary Repr of y after bit manipulation: " << format("{:b}", y) << endl;

    int m = y & (1 << 3);
    cout << "Binary Repr of m after bit manipulation: " << format("{:b}", m) << endl;

    int n = y & ~(1 << 3);
    cout << "Binary Repr of n after bit manipulation: " << format("{:b}", n) << endl;

    int p = n ^ (1 << 3);
    cout << "Toggle the nth bit of the integer: " << format("{:b}", p) << endl;
    int q = p & -p;
    cout << "To get the LSB : " << format("{:b}", q) << endl;

    cout << "number of trainling zero: " << __builtin_ctz(m) << endl;
    cout << "number of 1: " << __builtin_popcount(y) << endl;

    cout << "Swaping with XOR: " << endl;

    int a = 5, b = 6;
    cout << format("binary repr of a: {:b} and b: {:b}", a, b) << endl;

    a = a ^ b;
    cout << format("binary repr of a after a^b: {:b}", a) << endl;

    b = a ^ b;
    cout << format("binary repr of b after a^b: {:b}", b) << endl;

    a = a ^ b;
    cout << format("binary repr of a after a^b: {:b}", a) << endl;

    cout << format("Now a: {} and b: {}", a, b);
}