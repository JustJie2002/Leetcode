# Intuition
Given that k is the radius. I know that the size of each subarray we want to consider is 2 * k + 1. I notice that since each subarray has the same size, I'm able to maintain the sum from one subarray to the next subarray by just adding the right most element from the next subarray and subtracting the leftmost element from the current subarray.

Here's what I meant:
```
nums = [1, 2, 3, 4]
k = 1

Our first subarray is nums[0: 3]
[1, 2, 3, 4]
 L     R

the next subarray is nums[1: 4]
[1, 2, 3, 4]
    L     R
```
Notice that when moving the left pointer and the right pointer, the difference as L moves to L + 1, we're subtracting the nums[L] and R moves to R + 1, we're adding the nums[R + 1]. We call this technique, sliding window. Or more specifically here, fix size sliding window.

# Approach
We do a fix size sliding window. What that means is that, as we're iterating through the array, we only keep track of sum within a specific distance from current index. Here, each index we're iterating through is going to be our potential right pointer.

Once we reached to the point where the # of elements we've iterated through exceeds the fixed window size, we will subtract the previous left most element to maintain a fixed window sum. Then, given the right pointer and k, we're able to find the "center" of the subarray and set its average in the "res" array.

# Complexity
- Time Complexity: O(N)

- Space Complexity: O(N)
