/*
📌 Problem:
Given a queue and an integer k, reverse the first k elements of the queue while leaving the rest in the same order.

💡 Key Concept:
Use a stack for the first k elements, and a queue for the rest. Demonstrates hybrid usage.

🔍 Example:
Input: Queue = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
*/

#include <bits/stdc++.h>

using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    if (q.empty() || k > q.size() || k < 0)
        return;

    stack<int> st;

    for (int i = 0; i < k; ++i)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int rem = q.size() - k;
    for (int i = 0; i < rem; ++i)
    {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(std::queue<int> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

int main()
{
    std::queue<int> q;
    for (int i = 1; i <= 5; ++i)
        q.push(i);

    int k = 3;
    reverseFirstK(q, k);

    std::cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
