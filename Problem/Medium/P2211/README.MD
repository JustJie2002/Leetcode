# Intuition
case 1: 'L'
- not stack: do nothing since there's no way the current car will crash
- if top of stack is stationary, we will crash into them, collision += 1
- stack[-1] == 'R': 
  - collision += 2
  - pop from stack and now we're stationary
  - go to case 3

case 2: 'R'
- we don't know what will happen in the future so we can just append the car going R in the stack

case 3: 'S'
- while the top of the stack has cars going R, then they will crash into us and collision += 1.
- append the stationary in the stack

# Approach
Use stack to simulate the 3 cases written in intuition.

# Complexity
- Time Complexity: O(N)

- Space Complexity: O(N)
