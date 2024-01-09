First thing we can see from the constraint is that arrow.Length = 12. Something we can deduce from that is the fact that n is small enough that we can probably **brute force** this problem.

Back to the problem statement, let's highlight some key informations:
- The target has integer scoring sections ranging from **0 to 11** inclusive.
  - From this, we know that if we are simulating the process, the scoring section is 0-index not 1-index
- ... If ak < bk, then Bob takes k points. However, if ak == bk == 0, then nobody takes k points.
  - In other words, if alice shot a_i arrows onto target i, then bob **needs > a_i** arrows to win this section otherwise it's alice's points
  
Here, we're able to brute force by simulating all possibilities of Bob winning points. Suppose we're on target i, there's 2 possibilities: (1) Bob wants to win this section and (2) Bob doesn't want to win this section. Given these 2 scenarios how is Bob able to make the most out of each scenario:
1. Since Bob wants to win this section then we will need at least a_i + 1. However, considering that we may want to save more arrows to win other points, Bob should only use a_i + 1 to barely win i points.
2. Since Bob doesn't even want to win this section, there's no point of wasting arrows on this section. We will just skip/shoot nothing.

Now we have a couple options to solve this problem:
1. Recursion + Backtracking: each index has 2 paths and just simulate
2. Bitmask DP ⭐: I won't go too much into this but pretty much what I'm doing is that I represent each possibility as a [bitmask](https://www.geeksforgeeks.org/what-is-bitmasking/).
  - Ex: 0100 0100 0101
  - Here 0th, 2nd, 6th, and 10th bit are 1 referring to scenario 1
  - Other bits are 0 referring to scenario 2
  - Simulate

Time Complexity: O(N * 2^N) \
Space Complexity: O(N)