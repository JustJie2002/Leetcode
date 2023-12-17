
class Solution:
    def divideArray(self, a, k):
        n = len(a)

        a.sort()

        res = []
        for i in range(0, n, 3):
            if a[i + 2] - a[i] > k:
                return []
            res.append(a[i : i + 3])
        
        return res