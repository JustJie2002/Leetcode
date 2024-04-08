# Intuition
It might be easier to view it in terms of a point line where we have 2 segments, and we want to see whether they overlap. We can convert a time to a "point" by converting the time to second only.

# Approach
1. Convert both events to line segment
2. We can check for overlap by taking the max of both starting point and min of both ending point to check whether the new start is still less than or equal to the new end 


# Complexity
- Time Complexity: O(1)

- Space Complexity: O(1)
