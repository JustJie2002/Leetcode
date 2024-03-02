# Intuition
For this problem, we have to implement how we would normally do 2 integer addition but in reverse.

# Approach
Usually when we're doing 2 integer addition, we want to align each digits by their place and add them. Here, the listnode is already sorted in place order, so we just have to implement normal addition. \
Now we have to talk about the concept of a "carry". Whenever we add 2 numbers that sums up 10 or more, e.g. 5 + 6 = 11. We will have to carry the ten's place to the next digit place and keep the 1 to our current digit place. \
There will be a couple cases we have to cover:
- a = nullptr
  - b = nullptr
    - carry = 0, we will break because there's nothing we have to deal with
    - carry = 1, we just add a 1 at the end and break
  - b has a value, we will be adding b->val + carry
- a has a value
  - b = nullptr, we will be adding a->val + carry
  - b has a value, we will be adding a->val + b->val + carry

# Complexity
N is the size of the longest listnode
- Time Complexity: O(N)
- Space Complexity: O(N)