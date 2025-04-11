## 🎯 What is the Knapsack Problem?

> Given `n` items, each with a **weight** and **value**, and a knapsack with a maximum capacity `W`, choose items to maximize total value **without exceeding** the capacity.

---

## 🧠 Types of Knapsack Problems

| Problem Type | Can we take an item multiple times? | Item Count Limit? |
|--------------|--------------------------------------|--------------------|
| **0/1 Knapsack** | ❌ No (each item once)          | Yes (once only)     |
| **Unbounded Knapsack** | ✅ Yes (as many times as we want) | No limit          |
| **Bounded Knapsack** | ✅ Yes, but with a limit per item | Limited quantity  |
| **Subset Sum / Partition** | ❌ Value-less variation         | Yes                |

---

## 🔍 0/1 Knapsack — The Classic

### Problem Statement

You're given:
- `weights[]`: the weights of items
- `values[]`: the values of items
- `W`: total capacity of the knapsack

Pick items (0 or 1 times each) to **maximize value** without exceeding capacity.

---

### 🧠 DP Idea

- **State:**  
  `dp[i][W]` = max value from first `i` items with capacity `W`
  
- **Transition:**

  If you don't take the item:
  ```
  dp[i][W] = dp[i-1][W]
  ```

  If you take the item:
  ```
  dp[i][W] = value[i] + dp[i-1][W - weight[i]]
  ```

  Combine:
  ```
  dp[i][W] = max(take, not take)
  ```

- **Base case:**  
  `dp[0][W] = (weight[0] <= W ? value[0] : 0)`

---

### ✅ C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack01(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i == 0)
        return wt[0] <= W ? val[0] : 0;
    if (dp[i][W] != -1) return dp[i][W];

    int notTake = knapsack01(i - 1, W, wt, val, dp);
    int take = (wt[i] <= W) ? val[i] + knapsack01(i - 1, W - wt[i], wt, val, dp) : 0;

    return dp[i][W] = max(take, notTake);
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Max value: " << knapsack01(n - 1, W, wt, val, dp) << endl;
}
```

---

## 💡 Real-World Use Cases of Knapsack

| Scenario | Description |
|----------|-------------|
| **Budget Optimization** | Choose subset of projects to fund with limited budget |
| **Cargo Loading** | Maximize profit with weight constraints |
| **Investment Planning** | Select stocks/funds within a risk or budget constraint |
| **Memory/Resource Allocation** | Distribute tasks to minimize/maximize usage/value |
| **Cloud Cost Savings** | Choose right mix of instance types under cost/performance bounds |

---

## 🆚 Unbounded Knapsack

> You can take **any number of instances** of each item.

### Transition

```cpp
dp[i][W] = max(dp[i-1][W], val[i] + dp[i][W - wt[i]])
// Note: dp[i][W - wt[i]] instead of dp[i-1] — same row!
```

- Used in:
  - Coin change problems
  - Rod cutting
  - Infinite supply problems

---

## 🧠 How to Approach Knapsack Variants in Interviews

### Ask:
- **Can you take an item more than once?**
- **Are items indivisible?**
- **Do you care about max value, number of ways, min weight?**
- **What’s changing: capacity, index, count, sum...?**

---

## ✅ Recap of Core Variants

| Problem Name | Item Reuse | Output |
|--------------|------------|--------|
| 0/1 Knapsack | No         | Max value |
| Unbounded Knapsack | Yes | Max value |
| Subset Sum   | No         | Boolean |
| Partition Equal Subset Sum | No | Boolean |
| Count Subsets with Sum | No | Count |
| Minimum Subset Sum Difference | No | Min diff |
| Coin Change (ways) | Yes | Count of ways |
| Coin Change (min coins) | Yes | Minimum coins |

---

## 🔥 Next Step?

Would you like to:

1. Solve a **real-world style problem** like **"Minimum Coins to Make Amount"**?
2. Convert 0/1 knapsack into **tabulation and space-optimized** form?
3. Try a **challenge problem** with coaching?

Let me know how you want to move forward.