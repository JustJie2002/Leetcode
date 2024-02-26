# Intuition
If 2 trees are the same, then their subtrees must also be the same. Therefore, we can recursively check all of the subtrees synchronously.

# Approach
We can start traversing (Depth-First Search) at both of their root. Compare their values and traverse through the same path for both trees.

# Complexity
Suppose N is the # of nodes. \
Time Complexity: O(N) \
Space Complexity: O(1)