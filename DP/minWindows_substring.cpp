/*Question 6.6 (ADM)
Given strings S and T of length n and m respectively, find the shortest
window in S that contains all the characters in T in expected O(n + m) time.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t)
{
    if (t.empty() || s.empty())
        return "";

    // frequency map for character in t
    unordered_map<char, int> t_freq;
    for (char c : t)
    {
        t_freq[c]++;
    }

    // total number of unique cghar in t that must be in the window
    int required = t_freq.size();

    // two pointer for he sliding window
    int left = 0, right = 0;

    // variable to track the char in the current windows that match t's freq
    unordered_map<char, int> window_freq;
    int formed = 0;

    // result variable: (length, left, right)
    int min_len = INT_MAX;
    int min_left = 0;

    while (right < s.length())
    {
        // add the current char to the window
        char c = s[right];
        window_freq[c]++;

        // if the freq of the curr char matches the required freq in t
        if (t_freq.count(c) && window_freq[c] == t_freq[c])
        {
            formed++;
        }

        // try to conract the windows until ot no longer contains all char of t
        while (left <= right && formed == required)
        {
            char left_char = s[left];

            // Update the minimum window
            if (right - left + 1 < min_len)
            {
                min_len = right - left + 1;
                min_left = left;
            }

            // Remove the leftmost character from the window
            window_freq[left_char]--;
            if (t_freq.count(left_char) && window_freq[left_char] < t_freq[left_char])
            {
                formed--;
            }

            left++; // Contract the window
        }

        right++; // Expand the window
    }

    return (min_len == INT_MAX) ? "" : s.substr(min_left, min_len);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "CODEN";

    string result = minWindow(s, t);

    cout << "String S: " << s << endl;
    cout << "String T: " << t << endl;
    cout << "Shortest window: " << (result.empty() ? "None" : result) << endl;

    return 0;
}