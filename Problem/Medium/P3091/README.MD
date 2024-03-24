# Intuition
Let's try to understand the problem, we can perform 2 operations:
1. Add 1 to one of the elements in the array
2. Duplicate one of the elements in the array

Intuitively, if we were to perform operation 2, would we want to duplicate any element that is smaller than max(nums)? No. Since we want to minimize the operation used to get to sum of at least k, we want to use our operations more effectively. \
\
Now we know how to use operation 2 effectively, how to use operation 1 effectively? Well let's look at it this way. Assuming we have our answer array in the future and we know what the max(nums) is, do you think we can use that to our advantage? Well since we can only add 1 to one of the elements in the array, that means we definitely used at least max(nums) - 1 # of operation 1 to reach max(nums). Here, the optimal thing to do is to only add to 1 number so we can reach max(nums) as soon as possible. \
\
Now let's combine those 2 effective usage of operations 1 and 2. Suppose, we only add to 1 number until we reach max(nums), since we start off with a [1], we can just use op 1 until that 1 reaches max(nums) and then we can use op 2 until sum(nums) <= k.

# Approach
1. Let's enumerate through all possible max(nums) from 1 to k.
2. At each mx, we determine the # of op1 and op2 needed
3. update ans based on min(ans, op1 + op2)

# Complexity
- Time Complexity: O(k)

- Space Complexity: O(1)

# Note
There is an O(1) solution for this problem but I feel like this way is easier to visualize necessary observations.