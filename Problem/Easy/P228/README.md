# Intuition
Since it's sorted we just have to check for consecutive subarrays.

# Approach
Append a dummy element at the very end. (the same as the last element) We can set 0 as "start" and begin at index 1. \
Consider 2 cases:
- If current index is the same as the previous index then we consider it as the same consecutive subarray as the previous element
- Otherwise, we can append that range based on "start" and current index - 1. Then we can update "start" as current index

# Complexity
N is the length of the array
- Time Complexity: O(N)
- Space Complexity: O(N)