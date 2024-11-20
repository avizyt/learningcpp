#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    cout << arr[2] << endl;

    vector<int> vec = {1, 2, 3};
    cout << vec.at(2) << endl;
    vec.push_back(4);
    cout << vec.at(3) << endl;
    cout << vec.size() << endl;
    for (int i = 0; i <= vec.size(); i++)
    {
        cout << vec.at(i);
    }
}
