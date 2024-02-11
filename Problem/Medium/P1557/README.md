# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Suppose we have some edges: (from, to), if a node never shows up as "to", then we know that that vertex cannot be reach by any given vertex. Therefore, we have to start with those vertices.

# Approach
<!-- Describe your approach to solving the problem. -->
We just have to iterate through all edges and mark all "to" to reachable. Then we can just pick the vertices that are not reachable and those are our answer.

# Complexity
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
- Time complexity: O(E), where E is the # of edges

<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- Space complexity: O(n), where n is the # of vertices