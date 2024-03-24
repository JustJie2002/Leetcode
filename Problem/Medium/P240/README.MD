# Intuition
Consider the relationship between each grid to its neighbors. Assuming we have mat[i][j], we know that mat[i + 1][j] and mat[i][j + 1] are greater than mat[i][j] and mat[i - 1][j] and mat[i][j - 1] are less than mat[i][j].

# Approach
Start at the top-right corner. Adjust the position based on the comparison between mat[i][j] and target.
- mat[i][j] == target: We can just return true
- mat[i][j] < target: We underestimated it so i++
- mat[i][j] > target: We overestimated it so j--

# Complexity
- Time Complexity: O(n + m)

- Space Complexity: O(1)
