/*
📌 Problem:
Given a queue with an even number of integers, interleave the first half with the second half.

💡 Key Concept:
Splitting, requeuing — teaches queue reordering.

🔍 Example:
Input: [1, 2, 3, 4]
Output: [1, 3, 2, 4]
*/

#include <bits/stdc++.h>

using namespace std;

void interleaveQueue(queue<int> q)
{

    int n = q.size();

    if (n % 2 != 0)
    {
        cerr << "Queue size must be even to interlease.\n";
        return;
    }
    queue<int> q1;

    for (int i = 0; i < n / 2; ++i)
    {
        q1.push(q.front());
        q.pop();
    }

    while (!q1.empty())
    {
        q.push(q1.front());
        q1.pop();

        q.push(q.front());
        q.pop();
    }
}

void printQueue(const queue<int> &q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << "\n";
}

int main()
{
    queue<int> q;
    for (int i = 1; i <= 6; ++i)
        q.push(i);

    printQueue(q);
    interleaveQueue(q);
    printQueue(q);
}
