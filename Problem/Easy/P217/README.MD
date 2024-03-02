# Intuition
We just have to implement what they are asking.

# Approach
## Approach 1: Map/Dictionary
As we're iterating through the array, just keep track of how many times the current element has been seen using a map/dictionary. \
If the frequency of the current element is >= 2, then we can return true. Otherwise, if we finished iterating through the array and we still haven't seen an element with frequency >= 2, then we can just return false.

## Approach 2: Set
Suppose n is the number of elements in the array. If any element appears more than once in the array, then the # of distinct elements of the array should be less than n.

# Complexity
- Time Complexity for both: O(N)
- Space Complexity for both: O(N)