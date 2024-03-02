# Intuition
Simulate how we usually multiply 2 integers.

# Approach
Suppose we want to find the product of string a and b. There's a couple subproblems for this problem:
- Multiply each digit of a to the whole string b
- Fill some number of zeros to the right of the product based on their digit place. Suppose if it's string a's one's place, we fill no zeros, then 1, 2 ... .
- Add all of those up, we can use similar process of [P2. Add Two Numbers](../P2).

# Complexity
N = length of a, M = length of b
- Time Complexity: O(N * M)
- Space Complexity: O(N * M)