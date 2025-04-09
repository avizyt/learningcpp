#include <iostream>

using namespace std;

int main()
{
    cout << "Enter start and end of the range: " << endl;
    int start = 0, end = 0;
    // cout << "Start: " << endl;
    cin >> start >> end;

    // cout << "End: " << endl;
    // cin >> end;

    while (start <= end)
    {
        cout << start << " ";
        ++start;
    }
}