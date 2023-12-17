N = 10 ** 5

res = set()
for i in range(N):
    s = str(i)
    rev = s[::-1]
    res.add(int(s + rev))
    for j in range(10):
        if i != 0:
            res.add(int(s + str(j) + rev))
        else:
            res.add(j)

res = sorted(res)

class Solution:
    def minimumCost(self, a):
        n = len(a)
        a.sort()

        med = a[n // 2]
        it = bisect.bisect(res, med)
        p1 = res[it]
        p2 = res[it - 1]

        res1, res2 = 0, 0
        for x in a:
            res1 += abs(p1 - x)
            res2 += abs(p2 - x)
        
        return min(res1, res2)