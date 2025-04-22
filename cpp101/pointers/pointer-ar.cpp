#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Address of A_" << i << " = " << (arr + i) << std::endl;
        std::cout << "Value of A_" << i << " = " << arr[i] << std::endl;
    }
    return 0;
}