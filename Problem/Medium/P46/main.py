"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 05.26.2024 17:26:29
"""

class Solution:
    def permute(self, a):
        n = len(a)

        def has(mask, nth):
            return mask & (1 << nth)
        
        DONE = (1 << n) - 1

        ans, res = [], []
        def work(mask):
            if mask == DONE:
                ans.append(res[:])
                return

            for i in range(n):
                if not has(mask, i):
                    res.append(a[i])
                    work(mask | (1 << i))
                    res.pop()

        work(0)
        return ans

# ~ JustJie