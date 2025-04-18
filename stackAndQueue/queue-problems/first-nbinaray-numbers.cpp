/*
📌 Problem:
Given a number N, print the first N binary numbers in sequence.

💡 Key Concept:
Use a queue to generate binary numbers in level-order, like BFS in a binary tree.

🔍 Example:
Input: N = 5
Output: 1 10 11 100 101
*/

#include <bits/stdc++.h>

using namespace std;

void printFirstNBinaryNumbers(int n)
{
    queue<string> q;
    q.push(" 1");
    for (int i = 0; i < 5; i++)
    {
        string curr = q.front();
        q.pop();
        cout << curr << endl;
        q.push(curr + " 0");
        q.push(curr + " 1");
    }
}

// performance

void printBinary(int n)
{
    string res;
    while (n > 0)
    {
        res = (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}

void printBinWithoutQueue(int n)
{
    vector<string> bin(n);
    bin[0] = "1";
    for (int i = 1; i < n; ++i)
    {
        bin[i] = bin[(i - 1) / 2] + ((i % 2) ? '0' : '1');
        cout << bin[i] << "\n";
    }
}
int main()
{
    int n = 5;
    // printFirstNBinaryNumbers(n);
    // printBinary(n);
    printBinWithoutQueue(n);
}