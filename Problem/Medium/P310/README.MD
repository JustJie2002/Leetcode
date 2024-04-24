# Intuition
If we want to minimize the height of the tree, then we want to find such roots that would minimize the distance from the root to any leaves. We can do so by finding the centroids of the tree. This can be done by starting at the leaves of the tree (the nodes where there's only 1 other node that's connected to it) and peel it off the tree until only 1 - 2 nodes are left.

# Approach
1. Create an adjacency list as well as a degree array which tracks how many nodes are currently connected to this node.
2. Peel the tree like an onion starting at the nodes with degree of 1 (meaning there's only 1 other node connected to this node)
3. Do a layer'ed bfs until there's no more nodes left to peel and the nodes that are at the last layer to peel will be the centroids (good roots).

P.S. There is an edge case of n == 1 that will make this solution fail because there are no edges so degree will be 0 and it won't be detected to put into the queue. Therefore, we will have to manually take care of that.

# Complexity
- Time Complexity: O(N)

- Space Complexity: O(N)

Since M == N - 1, M will be upper bounded by N, therefore the complexity of each will be O(N).