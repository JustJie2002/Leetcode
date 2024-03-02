# Intuition
Get the leaves of both trees in order then compare them.

# Approach
We can do an [post-order traversal](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/) on both trees to only get the leaves. Then we can do a direct comparison between the leaves we get. 

# Complexity
N is the # of nodes
- Time Complexity: O(N)
- Space Complexity: O(N)