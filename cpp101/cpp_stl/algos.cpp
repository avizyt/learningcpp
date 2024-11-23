#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> numb = {3, 2, 5, 1, 4};

    // sorting algorithm
    sort(numb.begin(), numb.end());

    for (int num : numb)
    {
        cout << num << " " << endl;
    }

    // iterator to point
    vector<int>::iterator itr = numb.begin();
    cout << "First Element: " << *itr << " " << endl;

    // change iterator to point to the last element
    itr = numb.end() - 1;
    cout << "Last Element: " << *itr;
    return 0;
}