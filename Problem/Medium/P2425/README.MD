# Intuition
Let's understand a property of bitwise xor. Suppose we have an element, x. x ^ x = 0. This means that suppose there is an even number of x in an array and we xor all of them, then it's the same as 0. Similar, if there is an odd number of x in an array and we xor all of them, that's the same as only having 1 x. Therefore, let's think about this, having all elements in nums1 bitwise xor with all elements in nums2 is the same as having all elements in nums1 len(num2) amount of times and vice versa. So we just have to check the parity of len(num1) and len(num2) to see whether we have to include num1 or num2.

# Approach
1. Set ans to 0
2. If size of num2 is odd, then we xor all elements from num1 to ans. Otherwise, do nothing.
3. Similarly, if size of num1 is odd, then we xor all elements from num1 to ans. Otherwise, do nothing.

# Complexity
Suppose n = len(num1) and m = len(num2)
- Time Complexity: O(n + m)

- Space Complexity: O(1)
