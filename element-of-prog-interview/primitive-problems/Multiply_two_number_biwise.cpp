#include <iostream>

using namespace std;

int add(int a, int b)
{
    while (b != 0)
    {
        // find common set of bits (carry)
        int carry = a & b;

        // add without carrying
        a = a ^ b;

        // move carry to the left
        b = carry << 1;
    }
    return a;
}

int multiply(int a, int b)
{
    int result = 0;
    while (b > 0)
    {

        if (b & 1)
        {                            // check if current bit is 1
            result = add(result, a); // add current a to result
        }

        a <<= 1; // a = a*2
        b >>= 1; // b = b/2
    }

    return result;
}

int main()
{
    int a = 13, b = 9;
    std::cout << "Add: " << add(a, b) << "\n";
    std::cout << "Product: " << multiply(a, b) << "\n"; // 42
}