## Binary Search Algorithm in C++

### Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;               // Starting index
    int right = arr.size() - 1; // Ending index

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Sorted array
    int target = 7;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
```

---

### Explanation of the Code

1. **Function Declaration**:
   - The `binarySearch` function takes a constant reference to a vector (`const vector<int>& arr`) to avoid unnecessary copying and an integer `target` to find in the array.

2. **Initialization**:
   - `left` and `right` are initialized to the first and last indices of the array, respectively.

3. **Loop**:
   - The loop runs until `left` is greater than `right`, ensuring all possible positions are checked.

4. **Mid Calculation**:
   - `mid = left + (right - left) / 2`: This formula avoids integer overflow that could happen with `(left + right) / 2` for large values of `left` and `right`.

5. **Comparison**:
   - If `arr[mid] == target`, the function returns the index `mid`.
   - If `arr[mid] < target`, it means the target lies in the right half, so `left` is updated to `mid + 1`.
   - If `arr[mid] > target`, it means the target lies in the left half, so `right` is updated to `mid - 1`.

6. **Return Value**:
   - If the loop ends without finding the target, `-1` is returned, indicating the target is not in the array.

7. **Driver Code**:
   - A sorted array `arr` is passed to the `binarySearch` function along with the `target`.
   - The result is checked; if `result` is `-1`, the target was not found. Otherwise, the index is printed.

---

### Example Execution

#### Input:
Array: `{1, 3, 5, 7, 9, 11}`  
Target: `7`

#### Execution Steps:
1. `left = 0`, `right = 5`, `mid = 2`
   - `arr[mid] = 5`, which is less than `7`. Update `left = 3`.

2. `left = 3`, `right = 5`, `mid = 4`
   - `arr[mid] = 7`, which matches the target. Return `4`.

#### Output:
```
Element found at index 3
```