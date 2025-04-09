# Bitwise Operation and Tricks

## 🔧 Bitwise Operations: Quick Refresher

| Operator | Symbol | Description                      | Example          |
|----------|--------|----------------------------------|------------------|
| AND      | `&`    | Bit is 1 only if both bits are 1 | `5 & 3 = 1`      |
| OR       | `\|`   | Bit is 1 if either bit is 1      | `5 | 3 = 7`      |
| XOR      | `^`    | Bit is 1 if bits are different   | `5 ^ 3 = 6`      |
| NOT      | `~`    | Inverts all bits (one's comp)    | `~5 = -6`        |
| Left Shift | `<<` | Shifts bits left, multiplies by 2 | `5 << 1 = 10`   |
| Right Shift| `>>` | Shifts bits right, divides by 2  | `5 >> 1 = 2`     |

---

## 🧠 Intuition & Real-World Analogies

- `&`: Like intersection (both have to be 1)
- `|`: Like union (either or both can be 1)
- `^`: Like toggling a switch (1 if different)
- `~`: Flips all bits — like turning lights off if they're on and vice versa

---

## ⚡ Common Bitwise Tricks

### 1. **Check if a number is even or odd**
```cpp
bool isOdd(int n) {
    return n & 1; // last bit = 1 ⇒ odd
}
```

### 2. **Swap two numbers without temp**
```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### 3. **Multiply or divide by 2ⁿ (efficient!)**
```cpp
int x = 6;
int mul = x << 2; // 6 * 4 = 24
int div = x >> 1; // 6 / 2 = 3
```

### 4. **Count set bits (Brian Kernighan’s Algo)**
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // removes lowest set bit
        ++count;
    }
    return count;
}
```

### 5. **Check if n is power of 2**
```cpp
bool isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### 6. **Turn off the lowest set bit**
```cpp
n = n & (n - 1);
```

### 7. **Isolate lowest set bit**
```cpp
int lowestSetBit = n & (-n);
```

---

## 🔍 Practical Use Cases

### ✅ 1. **Bitmasking** (used in DP, subsets, permissions)
```cpp
int mask = 0b1011; // e.g. 4-bit mask

// Check if 3rd bit is set
if (mask & (1 << 2)) { ... }

// Set the 2nd bit
mask |= (1 << 1);

// Unset the 0th bit
mask &= ~(1 << 0);

// Toggle 1st bit
mask ^= (1 << 1);
```

### ✅ 2. **Subset generation**
```cpp
int n = 3; // 3 elements ⇒ 2^3 subsets
for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
            // include j-th element
        }
    }
}
```

### ✅ 3. **State compression in DP**
- You can represent a board state, visited nodes, etc., in an `int` (up to 32 bits).
- Efficient for problems like **"Travelling Salesman"**, **"Bit DP"**, **"Graph coloring"**.

### ✅ 4. **Permissions and Flags** (real-world analogy)
```cpp
enum Permission {
    READ = 1 << 0,
    WRITE = 1 << 1,
    EXEC = 1 << 2
};

int userPerm = READ | WRITE;

// Check
if (userPerm & EXEC) { /* ... */ }
```

---

## 🧪 Practice Prompts (Bit Mastery Level)

1. Write a function to count set bits in `O(1)` time using a lookup table.
2. Given an integer array where every element appears twice except one, find that one.
3. Implement XOR-based Trie for maximum XOR pair.
4. Solve "Minimum Number of Flips to Convert Binary Matrix to Zero Matrix" (Leetcode Hard) using bitmask + BFS.
5. Write a program to add two numbers without `+` or `-`.

---

Would you like me to create a **Bitwise Operations Cheatsheet**, or walk you through one of the trickier use cases like **subset DP**, **bitmask BFS**, or a **coding challenge** next?