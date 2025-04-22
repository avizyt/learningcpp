
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {1, 2, 3, 4, 5};
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    std::cout << arr.at(i) * 2 << std::endl;
  }

  return 0;
}
