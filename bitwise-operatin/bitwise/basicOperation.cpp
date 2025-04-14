#include <iostream>
#include <bitset>
#include <format>

using namespace std;

int main()
{
    int a = 13;
    int b = 9;
    cout << "a = " << format("{:b}", a) << endl;
    cout << "b = " << format("{:b}", b) << endl;

    int a_and_b = a & b;
    cout << format("{:b}", a_and_b) << endl;

    int a_or_b = a | b;
    cout << format("{:b}", a_or_b) << endl;

    int a_xor_b = a ^ b;
    cout << format("{:b}", a_xor_b) << endl;

    int lshift_a = a << 1;
    cout << format("{:b}", lshift_a) << endl;

    int rshift_a = a >> 1;
    cout << format("{:b}", rshift_a) << endl;
}