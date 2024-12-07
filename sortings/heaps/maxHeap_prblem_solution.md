# Question 4.19 (ADM)
You wish to store a set of n numbers in either a max-heap or a sorted array.
For each application below, state which data structure is better, or if it does not
matter. Explain your answers.
(a) Find the maximum element quickly.
(b) Delete an element quickly.
(c) Form the structure quickly.
(d) Find the minimum element quickly.



### (a) **Find the maximum element quickly**  
**Better data structure**: **Max-Heap**  
**Explanation**:  
- In a **max-heap**, the maximum element is always at the root (index 0 in an array representation), so accessing it is **O(1)**.  
- In a **sorted array**, finding the maximum requires accessing the last element, which is also **O(1)**.  
However, max-heaps are more versatile when other operations (like insertions or deletions) are needed in addition to retrieving the maximum, making the max-heap better overall for this task.  

---

### (b) **Delete an element quickly**  
**Better data structure**: **Sorted Array**  
**Explanation**:  
- In a **max-heap**, deleting an element requires first locating it (which takes **O(n)**), then reheapifying the heap (which takes **O(\log n)**). This makes deletion **O(n)** in the worst case.  
- In a **sorted array**, deleting an element involves finding its position using binary search (**O(\log n)**) and shifting the elements, which is **O(n)** in total.  
Although both have similar asymptotic complexity, in practice, sorted arrays are simpler and faster for deletion in many cases.  

---

### (c) **Form the structure quickly**  
**Better data structure**: **Max-Heap**  
**Explanation**:  
- Building a **max-heap** from an unsorted array can be done in **O(n)** time using the heapify process.  
- Forming a **sorted array** requires sorting the numbers, which takes **O(n \log n)** time using efficient sorting algorithms (e.g., Merge Sort or Quick Sort).  

Thus, max-heaps are faster to construct.

---

### (d) **Find the minimum element quickly**  
**Better data structure**: **Sorted Array**  
**Explanation**:  
- In a **max-heap**, the minimum element is not easily accessible, requiring a scan of all leaf nodes (approximately half the array), which takes **O(n)** in the worst case.  
- In a **sorted array**, the minimum element is the first element, accessible in **O(1)** time.  

A sorted array is much better for finding the minimum.  

---

### **Summary**  
| **Application**                | **Better Data Structure** | **Reason**                                   |
|---------------------------------|---------------------------|----------------------------------------------|
| (a) Find the maximum quickly    | Max-Heap                 | Root contains maximum, accessible in **O(1)** |
| (b) Delete an element quickly   | Sorted Array             | Binary search + shifting is simpler and faster |
| (c) Form the structure quickly  | Max-Heap                 | Built in **O(n)** using heapify              |
| (d) Find the minimum quickly    | Sorted Array             | Minimum is the first element, accessible in **O(1)** |