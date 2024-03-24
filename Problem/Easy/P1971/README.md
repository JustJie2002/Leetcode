
# Intuition
In this problem, given a bunch of edges forming a graph, we're trying to find out whether the node "source" and "destination" are connected in the given graph.

# Approach
## Approach 1: Graph Traversal
We can easily create an adjacency list using the edges provided. Then traversal starting from the "source" node. If we're visited the "destination" node then we return true, otherwise false.

## Approach 2: Union Find/DSU
Another way to say that node x is connected to node y is that they are within the same component. Therefore, we're able to use a data structure called Union Find (aka Disjointed Set Union | DSU) to determine whether node "destination" is within the same component as node "source".

# Complexity
## For approach 1
- Time Complexity: O(N + M)
- Space Complexity: O(N)

## For approach 2
- Time Complexity: O(M + $\alpha$(N))
- Space Complexity: O(N)