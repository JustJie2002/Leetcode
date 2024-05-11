

"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    def employeeFreeTime(self, schedule):
        times = []
        for work_time in schedule:
            times.extend(work_time)

        times.sort(key = lambda t : (t.start, t.end))

        n = len(times)
        p = 0
        def get():
            nonlocal p
            t = times[p]
            p += 1
            return t

        cur = get()
        ans = []
        while p < n:
            res = get()
            if cur.end >= res.start:
                cur.end = max(cur.end, res.end)
            else:
                add = Interval(cur.end, res.start)
                ans.append(add)
                cur = res
        return ans