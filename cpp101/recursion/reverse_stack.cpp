#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// void helper(stack<int>& st, int k){
//     if (st.empty()){
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     helper(st, k-1);
//     st.push(temp);
// }
void helper(stack<int>& st){
    if (st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    helper(st);
    st.push(temp);
}

void reverse(stack<int>& st){
    if(st.empty()){
        return;
    }

    int size = st.size();
    // helper(st, size);
    helper(st);
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

    reverse(st);

    cout << "after reverse: \n";
    stack<int> rev_st = st;
    while (!rev_st.empty()){
        cout << rev_st.top() << " ";
        rev_st.pop();
    }
    cout << endl;
}