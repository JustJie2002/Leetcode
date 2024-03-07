# Intuition
Suppose we have this rectangle that has the maximum area as the answer of our specific input. It has a dimension of W x H. We know that there must be an index of element within that range that has an element of exactly H where the remaining height is >= H. \
Assuming that we know the index of H, let's call it "i". How can we get the maximum area based on the index "i"? We can just keep expanding left as long as the height is >= H and the same with R. \
The naive approach is going to be $O(N^2)$ using double for loop but we can optimize that with monostack.

# Approach
Use monostack to find the index of the element that is less than current i and mark those as L. Use monostack to find index of the element that is less than current i and mark those as R.

Enumerate through each height in the array. Take each height as a pivot of what H of the rectangle will be and W will just be R[i] - L[i]. Then the maximum area pivoted at this index will just be W * H.

# Complexity
- Time Complexity: O(N)

- Space Complexity: O(N)
