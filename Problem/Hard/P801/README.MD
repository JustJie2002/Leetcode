# Intuition
This problem is just to decide whether each indices should swap or not. Let's understand what is the pre-req of each indices before they swap. Suppose we want to swap the i-th index, what do we want to consider? We want to make sure that after swapping, a[i] > a[i - 1] and b[i] > b[i - 1]. Therefore, there's 4 possible scenarios we have to consider:
1. We don't swap i and i - 1, a[i] > a[i - 1] and b[i] > b[i - 1]
2. We don't swap i but do swap i - 1, a[i] > b[i - 1] and b[i] > a[i - 1]
3. We swap i but don't swap i - 1, a[i] > b[i - 1] and b[i] > a[i - 1]
4. We swap i and i - 1, a[i] > a[i - 1] and b[i] > b[i - 1]

# Approach
We will be using dp for this problem.

WHAT:
1. dp[i][0]: the minimum swaps needed to maintain an increasing order from [0: i] without swapping i-th index
2. dp[i][1]: the minimum swaps needed to maintain an increasing order from [0: i] swapping i-th index

WHERE: max(dp[n - 1]) \
HOW: Based on whether each case applies
1. dp[i][0] = min(dp[i][0], dp[i - 1][0])
2. dp[i][0] = min(dp[i][0], dp[i - 1][1])
3. dp[i][1] = min(dp[i][1], dp[i - 1][0])
4. dp[i][1] = min(dp[i][1], dp[i - 1][1])

# Complexity
Set n := len(a)
- Time Complexity: O(n)

- Space Complexity: O(n)
