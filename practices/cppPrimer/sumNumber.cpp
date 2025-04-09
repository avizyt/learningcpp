#include <iostream>

int sum()
{
    int start = 50;
    int sum = 0;

    while (start <= 100)
    {
        sum += start;
        ++start;
    }
    return sum;
}

int main()
{
    std::cout << sum();
}