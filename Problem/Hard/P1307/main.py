"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 05.27.2024 14:09:34
"""
from itertools import *
from functools import *
from collections import *

LIM = 8

class Solution:

    def __init__(self):
        self.pw10 = [1]
        for _ in range(LIM):
            self.pw10.append(self.pw10[-1] * 10)

    def isSolvable(self, words, res):
        cs = []
        pos = defaultdict(int)
        non_zero = set()
        for word in words:
            n = len(word)
            for i, c in enumerate(word):
                if i == 0 and n > 1:
                    non_zero.add(c)
                if c not in pos:
                    cs.append(c)
                pos[c] += self.pw10[n - i - 1]

        for i, c in enumerate(res):
            if i == 0 and n > 1:
                non_zero.add(c)
            n = len(res)
            if c not in pos:
                cs.append(c)
            pos[c] -= self.pw10[n - i - 1]

        m = len(cs)

        def has(mask, nth):
            return mask & (1 << nth)

        def rec(i, used, difference):
            if i == m:
                return difference == 0

            for d in range(10):
                if not has(used, d) and (cs[i] not in non_zero or d > 0):
                    if rec(i + 1, used | (1 << d), difference + pos[cs[i]] * d):
                        return True
            return False

        return rec(0, 0, 0)


# ~ JustJie