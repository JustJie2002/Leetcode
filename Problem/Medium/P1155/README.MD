# Intuition
When we see something like this, the natural idea at first is to think of the brute force. Something like recursively find all paths that takes n rolls and get to a sum of t like:
```py
def brute_force(rolls_left, sum_left):
    if rolls_left == 0:
        if sum_left == 0:
            return 1
        else:
            return 0
    if sum_left <= 0:
        return 0
    ans = 0
    for roll in range(1, k + 1):
        ans += brute_force(rolls_left - 1, sum_left - roll)
    return ans
```
This is a quick brute force code in python. But what is the time complexity for this? Well at the worst possible case where target = 1000, n = 30, k = 30, even if we roll a 30 every time, we will at most get 900 so we're forced to get to the end. Each individual recursive call branches out to k recursive calls based on the rolls. Therefore, the time complexity will be $O(k^n)$, which is very big, how can we improve this?

We say that there's a total of $k^n$ paths but will each of those paths be unique? No. Since 30 * 30 = 900, the sum will at most be 900 meaning that our "state" will be upper bounded by the unique paths given. Let's think about it this way: imagine I rolled 1 at the first round and 2 on the second round, that summed up to 3. Is that different from 2 on the first round and 1 on the second? No. Therefore, we're getting to the dynamic programming realm.

When we're seeing overlapping patterns in a problem, there's a high chance of the problem being solved or at least optimized using dynamic programming (dp). A quick way to remind yourself what to expect when solving a dp problem: \
WHAT - identify the dimensions and what does each state represent in the context of the problem \
WHERE - where can we get the answer or at least our need \
HOW - how can we get the values for current state given previously solved states

# Approach
WHAT: dp[i][j] = # of possible ways at i'th roll, we can get a sum of j \
WHERE: dp[n][t] \
HOW: dp[i][j] = $\sum_{l = j - k}^{j-1} dp[i - 1][l]$, such that l >= 0

# Complexity
- Time Complexity: O(ntk)

- Space Complexity: O(n) \
I wrote O(n) here because at every iteration, there will be at most 2 size n arrays allocated.

