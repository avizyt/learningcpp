#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char C[4];
    C[0] = 'A';
    C[1] = 'B';
    C[2] = 'C';
    C[3] = 'D';
    C[4] = '\0';

    string b = "ABCD";
    int len = strlen(C);
    cout << C << endl;
    cout << len << endl;
    cout << format("Size in bytes: {}", sizeof(b));
    cout << b << endl;

    return 0;
}