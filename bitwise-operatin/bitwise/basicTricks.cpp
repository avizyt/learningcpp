#include <iostream>
#include <bitset>
#include <format>
#include <vector>

using namespace std;

bool isOdd(int n)
{
    return n & 1;
}

int swap(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return a, b;
}

int countBits(int n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        ++c;
    }
    return c;
}

int main()
{
    int a = 23;
    cout << format("{:b} ", a) << endl;
    cout << countBits(a);
}
// int main()
// {
//     vector<int> arr = {11, 22, 33, 44, 54, 66, 77, 88, 99};
//     for (int item : arr)
//     {
//         if (isOdd(item))
//         {
//             cout << item << " is Odd" << endl;
//         }

//         else
//         {
//             cout << item << " is Even" << endl;
//         }
//     }
// }