
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int V = 5;
  vector<int> arr(V);
  vector<bool> barr(V, false);
  int i = 1;
  for (bool item : barr)
  {
    if (!item == true)
    {
      arr.push_back(V * i);
      i++;
    }
  }

  for (int val : arr)
  {
    cout << val << " ";
  }
}
