#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class WeightedPicker
{
private:
    vector<int> prefixSum;
    int totalWeight;

public:
    WeightedPicker(const vector<int> &weights)
    {
        totalWeight = 0;
        for (int weight : weights)
        {
            totalWeight += weight;
            prefixSum.push_back(totalWeight);
        }
    }

    int pickIndex()
    {

        // random value in range [1, totalWeights]
        int randomValue = 1 + rand() % totalWeight;

        // find the smallest where randomValue <= prefixSum[index]
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), randomValue - 1);
        return it - prefixSum.begin();
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    vector<int> weights = {1, 3, 2};
    WeightedPicker picker(weights);

    // picking 10 times
    cout << "Picked indices:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << picker.pickIndex() << " ";
    }
    cout << endl;

    return 0;
}