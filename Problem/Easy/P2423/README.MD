# Intuition
Since the constraint is really small then we can simulate what the problem is saying.

# Approach
1. Get the frequency of all characters
2. Iterate through all characters and if the letter exist in the string i.e. frequency of the character != 0. Then subtract one from the frequency of the characters
3. Check whether all existing frequencies are the same
4. Add back the one and continue until all characters are the same

# Complexity
Suppose A = 26 and n = len(word)
- Time Complexity: O(n + A$^2$)

- Space Complexity: O(A)

# Note
We can reduce this down to O(n) by doing some case analysis. See if you can think of what cases there are? If I happen to come back to this question in the future, then I will create a file called code2.cpp to solve it in O(n).

Also, we can essentially write O(A$^2$) and exclude n because n is less than A$^2$ so we won't need to include that. However, A is usually consider has a constant factor in most cases. I chose to include it here because it's a big constant factor that cannot be ignored as n is so small.