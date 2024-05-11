import heapq

class Solution:
    def findMaximizedCapital(self, k, w, p, c):
        n = len(p)
        items = sorted((x, y) for x, y in zip(c, p))
        heap = []
        i = 0
        for _ in range(k):
            while i < n and items[i][0] <= w:
                heapq.heappush(heap, -items[i][1])
                i += 1
            if not heap:
                break
            w += -heapq.heappop(heap)
        return w