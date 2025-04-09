#include <iostream>

using namespace std;

unsigned Multiply(unsigned x, unsigned y)
{
    unsigned sum = 0;
    while (x)
    {
        // Examines each bit of x
        if (x & 1)
        {
            sum = Add(sum, y);
        }

        x >>= 1, y <<= 1;
    }

    return sum;
}

unsigned Add(unsigned a, unsigned b)
{
    unsigned sum = 0;
    unsigned carryin = 0;
    unsigned k = 1, temp_a = a, temp_b = b;
    while (temp_a || temp_b)
    {
        unsigned ak = a & k, bk = b & k;
        unsigned carryout = (ak & bk) | ((ak & carryin) | (bk & carryin));

        sum |= (ak ^ bk ^ carryin);
        carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
    }
    return sum | carryin;
}

int main()
{
    unsigned x = 13;
    unsigned y = 9;
    unsigned res = Multiply(x, y);
    cout << res << "\n";
}