from collections import *
from itertools import *

class Solution:
    def findMissingAndRepeatedValues(self, grid):
        n = len(grid)

        freq = Counter(chain(*grid))
        for x in range(1, n * n + 1):
            if freq[x] == 0:
                b = x
            if freq[x] == 2:
                a = x
        return [a, b]