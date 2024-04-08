# Intuition
Since we are sure that we will be given a valid parentheses string, in order to find maximum depth, we can just simulate by seeing which depth we're currently in and update the answer by checking ().

# Approach
set depth := 0 \
set ans := 0 \
iterate through the string and if the character is open parentheses, depth += 1, if the character is closed parentheses, depth -= 1. Update ans = max(ans, depth)

# Complexity
n = length of s
- Time Complexity: O(n)

- Space Complexity: O(1)
