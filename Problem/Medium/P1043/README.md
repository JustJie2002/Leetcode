WHAT: dp[i] - maximum sum after partition from 0 to i \
WHERE: dp[n - 1] or dp[n] depending on whether you're doing 0-index or 1-index \
HOW: dp[i] = max(dp[i - j] + max(arr[i - j:i])), such that i - j < k

Time Complexity: O(NK) \
Space Complexity: O(N)