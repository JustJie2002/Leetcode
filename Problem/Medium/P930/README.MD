# Intuition
Since we want to find the number of subarrays that sums up to "target", we can view this problem the same way as how to we view [two sum](https://leetcode.com/problems/two-sum). How? Suppose we have a subarray, nums[L : R + 1]. We can say that sum(nums[L : R + 1]) = sum(nums[: R + 1]) - sum(nums[: L]). In words, sum up to index R - sum up to index L - 1 will give us the sum between L and R.

# Approach
If we want to find # of subarrays that sum up to goal, for each index, we will maintain this running sum called "cur". We want to find # of occurences where target = cur - (previously seen prefix sum). We can rewrite that equation to (previously seen prefix sum) = last - goal, which in this cases is just finding the number of times where last - goal occurred 

# Complexity
- Time Complexity: O(N)

- Space Complexity: O(N)
