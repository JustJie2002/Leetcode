# Intuition
Since each grid is "unlocked" at a certain time. Why don't we just sort grid based on their unlocked time. Then we just have to iterate through the time and unlock them one by one. Then, use a way to check whether, after unlocking all grid with unlocking time <= t, there's a path between (0, 0) and (n - 1, n - 1)

# Approach
First, we can group all of the grids with same time in a map (tree map). Since we grouped it in a tree map, everything will be sorted by time. Now we can use a [DSU/Union Find](https://www.youtube.com/watch?v=ayW5B2W9hfo) to find whether (0, 0) is connected (n - 1, n - 1). This is because we can consider every single coordinate of the grid as their individual component, a coordinate is only being connected to another component when their unlocking time and their neighbor's unlocking time is <= current time. Then, we can quickly find whether the start and end is connected. Lastly, we continue doing that until we find a time where start and end is connected and we can just return the time.


# Complexity
- Time Complexity: $O(N^2)$

- Space Complexity: $O(N^2)$
