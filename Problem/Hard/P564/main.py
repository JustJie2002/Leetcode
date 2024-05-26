"""
author : Jie Chen (3rd Year CS)
school : Rochester Institute of Technology
"""

class Solution:
    def nearestPalindromic(self, val):
        n = len(val)
        v = int(val)

        if n == 1:
            return str(v - 1)
        
        cands = [
            int("9" * (n - 1)),
            (10 ** n) + 1
        ]

        half = val[: n // 2]
        pre = int(half)
        for options in [pre - 1, pre, pre + 1]:
            t = str(options)
            if len(t) != len(half):
                continue
            if options == 0:
                continue
            if n % 2 == 0:
                cands.append(int(t + t[::-1]))
            else:
                rt = t[::-1]
                for mid in range(10):
                    cands.append(int(t + str(mid) + rt))

        def get(x):
            return abs(x - v)

        ans = 10 ** 20
        for cand in sorted(cands):
            if cand == v:
                continue
            cand_dif = get(cand)
            ans_dif = get(ans)
            if cand_dif < ans_dif:
                ans = cand
            elif cand_dif == ans_dif and cand < ans:
                ans = cand
        
        return str(ans)