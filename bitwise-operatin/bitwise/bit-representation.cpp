#include <iostream>
#include <bitset>
#include <format>

using namespace std;

int main()
{
    int a = 13;
    // int b = 9;
    cout << "a = " << format("{:b}", a) << endl;
    // cout << "b = " << format("{:b}", b) << endl;

    for (int i = 31; i >= 0; i--)
    {
        if (a & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
}