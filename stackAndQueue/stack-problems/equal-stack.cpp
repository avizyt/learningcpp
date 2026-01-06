
#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> buildHeightSet(const vector<int> &arr) {
  set<int> heights;
  int total = 0;
  for (int i = arr.size() - 1; i >= 0; --i) {
    total += arr[i];
    heights.insert(total);
  }
  return heights;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
  set<int> s1 = buildHeightSet(h1);
  set<int> s2 = buildHeightSet(h2);
  set<int> s3 = buildHeightSet(h3);

  vector<int> common;
  for (int height : s1) {
    if (s2.count(height) && s3.count(height)) {
      common.push_back(height);
    }
  }

  return common.empty() ? 0 : *max_element(common.begin(), common.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> h1 = {3, 2, 1, 1, 1};
  vector<int> h2 = {4, 3, 2};
  vector<int> h3 = {1, 1, 4, 1};

  int height = equalStacks(h1, h2, h3);
  std::cout << height << std::endl;

  return 0;
}