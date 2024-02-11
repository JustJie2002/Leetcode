# Editorial
## Approach 1: Brute Force

We can use a nested for loop to enumerate "value 1" and "value 2" until we find such values that sum up to "target"

A: List[int] = the array of intgers
N: int = size of A
target: int = the targetted sum we want to find

Pseudocode:
```
i from 0 to N - 1 do
  j from i + 1 to N - 1 do
    if A[i] + A[j] == target:
      return [i, j]
```

First for loop enumerates value 1 and second for loop enumerates value 2. \
Notice how j starts at i + 1 not 0, this is because we don't want to enumerate through the duplicate values.

TC: O(N^2) \
SC: O(N^2)