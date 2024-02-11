
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
In this problem, given a bunch of edges forming a graph, we're trying to find out whether the node "source" and "destination" are connected in the given graph.

# Approach
<!-- Describe your approach to solving the problem. -->
## Approach 1: Graph Traversal
We can easily create an adjacency list using the edges provided. Then traversal starting from the "source" node. If we're visited the "destination" node then we return true, otherwise false.

## Parooach 2: Union Find/DSU
Another way to say that node x is connected to node y is that they are within the same component. Therefore, we're able to use a data structure called Union Find (aka Disjointed Set Union | DSU) to determine whether node "destination" is within the same component as node "source".

# Complexity
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
- Time Complexity 1: O(N + M)
- Time Complexity 2: O(M + alpha(N))

<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- Space Complexity 1: O(N)
- Space Complexity 2: O(N)