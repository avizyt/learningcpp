#include <iostream>
using namespace std;

int Increment(int a)
{
    a = a + 1;
    return a;
}
void IncCallByRef(int *p)
{
    *p = (*p) + 1;
}

int main()
{
    int a = 10;
    int *p = &a;
    int inc_a = Increment(*p);
    int *q = &inc_a;

    // std::cout << "Address of a = " << p << std::endl;
    // std::cout << "Address of inc_a = " << q << std::endl;

    // std::cout << "inc_a = " << *q << std::endl;
    IncCallByRef(&a);
    std::cout << a << std::endl;
    std::cout << *p << std::endl;
}