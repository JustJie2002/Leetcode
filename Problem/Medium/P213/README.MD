# Intuition
First we have to understand some key information from the question:
- Arranged in a circle
- Popo will come if 2 adjacent houses are robbed
- We want maximum amount of money we can rob without getting popo's attention

We know this is a dp problem because we can turn the results of some subproblem into use for other subproblems which can result in the answer. (This part may make more sense after seeing the states of dp)

# Approach
Whenever we solve a DP (Dynamic Programming) problem we want to know 3 things:
- WHAT: What are the states of dp? What is the meaning of each
- WHERE: Where will the answer be stored?
- HOW: How will we be solving each dp state?

WHAT: 
dp[i][0] - Maximum amount of money we can rob with robbing first house
dp[i][1] - Maximum amount of money we can rob without robbing first house

WHERE: max(dp)

HOW:
1. dp[0][0] = a[0] \
If we start at house 0, that's only house we can rob so far so the max amount will just be a[0]
1. dp[0][1] = -inf \
It's impossible to not rob house 0 being at house 0 so we can "skip" that one by assigning it to negative infinity
1. dp[i][k] = a[i] + max(dp[j][k]) such that j - i >= 2 and 1 < i < n - 1
2. dp[n - 1][0] = -inf and dp[n - 1][1] = a[i] + max(dp[j][k]) \
If we rob last house then we can't rob first house since everything is circular.

# Complexity
- Time Complexity: O(N^2)
- Space Complexity: O(N)