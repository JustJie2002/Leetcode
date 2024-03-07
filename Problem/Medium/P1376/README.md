# Intuition
First thing we can see is that this structure is a tree because a cycle cannot exist in a hierarchical structure. Therefore, the number of minutes to inform all employees will be the one of the path from root to the leaves.

# Approach
We can dfs from the root and sum from the root to the leaves. Once we reach the leaves, we can update the answer based on path sum (sum of inform time).

# Complexity
N is the number of nodes
- Time Complexity: O(N)

- Space Complexity: O(1)
