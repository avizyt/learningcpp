#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void helper(stack<int>& st, int k){
    if (k == 1){
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();

    helper(st, k-1);
    st.push(temp);

}

void deleteMiddle(stack<int>& st){
    if (st.empty()) return;

    int size = st.size();
    helper(st, size/2 + 1);
}

int main() {
    stack<int> st;

    vector<int> arr = {1,2,3,4,5};
    for (int num: arr){
        st.push(num);
    }
    cout << "before deleting middle: ";
    stack<int> temp = st;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;


    deleteMiddle(st);

    cout << "After deleting middle: ";
    stack<int> new_st = st;
    while (!new_st.empty()) {
        cout << new_st.top() << " ";
        new_st.pop();
    }
    cout << endl;

    return 0;

}