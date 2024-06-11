"""
author: Jie Chen
"""

class Solution:
    def combinationSum(self, a, t):
        n = len(a)

        ans, res = [], []
        def recurse(i, tot):
            if tot > t:
                return
            if tot == t:
                ans.append(res[:])
                return
            if i == n:
                return

            res.append(a[i])
            recurse(i, tot + a[i])
            res.pop()

            recurse(i + 1, tot)

        recurse(0, 0)
        return ans