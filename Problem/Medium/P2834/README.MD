# Intuition
If we want to minimize the sum of the "beautiful array", then we have to use as small of a number as possible. Suppose we can only add distinct, positive integers, that means there are at most $\lfloor\frac{target - 1}{2}\rfloor$ pairs of integers that can sum up to target. Using that knowledge, we can always use the smaller element of the pairs to add to our beautiful array and never add the bigger ones so there will never be 2 elements that can sum up to target. \
What if $\lfloor\frac{target - 1}{2}\rfloor < n$? Well since we can't add the bigger portion, we can just start adding at target and add until there are $n$ elements in the array. But the naive approach would be $O(n)$ and that is too much for $n \leq 1e9$, how can we improve that? \
Since we know that we will be summing all integers in the range from 1 to $\lfloor\frac{target - 1}{2}\rfloor$, we have a convenient math formula named [gauss summation](https://letstalkscience.ca/educational-resources/backgrounders/gauss-summation). In short, it allows us to sum from 1 to n using a single formula.

# Approach
Set m to $\lfloor\frac{target - 1}{2}\rfloor$ \
Case 1: n <= m \
Add from 1 up to n.

Case 2: n > m \
1. Add from 1 up to m
2. Add from target up to target + (n - m) - 1

# Complexity
- Time Complexity: O(1)

- Space Complexity: O(1)
