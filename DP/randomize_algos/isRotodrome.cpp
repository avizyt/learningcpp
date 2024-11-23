/*Question 6.8 (ADM)
A pair of English words (w1, w2) is called a rotodrome if one can be circularly
shifted (rotated) to create the other word. For example, the words (windup,
upwind) are a rotodrome pair, because we can rotate “windup” two positions
to the right to get “upwind.”
Give an efficient algorithm to find all rotodrome pairs among n words of length
k, with a worst-case analysis. Also give a faster expected-time algorithm based
on hashing.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

// generate all rotation of a word
vector<string> generateRotations(const string &word)
{
    vector<string> rotations;
    int n = word.size();
    string rotated = word;
    for (int i = 0; i < n; i++)
    {
        rotated = rotated.substr(1) + rotated[0];
        rotations.push_back(rotated);
    }
    return rotations;
}

vector<pair<string, string>> findRotodromePairsHashing(const vector<string> &words)
{
    unordered_map<string, set<string>> hashMap;
    vector<pair<string, string>> result;

    for (const string &word : words)
    {
        vector<string> rotations = generateRotations(word);
        for (const string &rotation : rotations)
        {
            hashMap[rotation].insert(word);
        }
    }

    // indentify unique pairs
    set<pair<string, string>> seen;
    for (const auto &[key, valueSet] : hashMap)
    {
        vector<string> valueVec(valueSet.begin(), valueSet.end());
        for (size_t i = 0; i < valueVec.size(); ++i)
        {
            for (size_t j = i + 1; j < valueVec.size(); ++j)
            {
                pair<string, string> pair = {valueVec[i], valueVec[j]};
                if (seen.find(pair) == seen.end())
                {
                    result.push_back(pair);
                    seen.insert(pair);
                }
            }
        }
    }

    return result;
}
int main()
{
    vector<string> words = {"windup", "upwind", "rotate", "teator", "hello"};
    vector<pair<string, string>> rotodromePairs = findRotodromePairsHashing(words);

    cout << "Rotodrome Pairs:\n";
    for (auto &pair : rotodromePairs)
    {
        cout << pair.first << " <-> " << pair.second << endl;
    }

    return 0;
}
