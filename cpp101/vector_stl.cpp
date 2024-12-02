
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> arr;

  for(int i=0; i<= 10; i++){
    arr.push_back(i*2);
  }
  for(int item: arr){
  cout << item << endl;
  }

  for(int x: arr){
    cout << x*2 <<endl;
  }

  sort(arr.begin(), arr.end());
}
