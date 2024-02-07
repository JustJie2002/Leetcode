LIM = 2 ** 31

class Solution:
    def splitIntoFibonacci(self, s):
        n = len(s)
        
        if s == '0' * n:
            return [0] * n
        
        def sim(a, b, j):
            c = 0
            path = [int(a), int(b)]
            w = sum(path)
            while j < n: # O(N)
                if c == 0 and s[j] == '0':
                    return []
                c *= 10
                c += int(s[j])

                if c >= LIM:
                    return []

                if c == w:
                    path.append(c)
                    w = path[-1] + path[-2]
                    c = 0
                elif c > w:
                    return []
                j += 1
            if c != 0:
                return []
            return path
        
        a = ""
        for i in range(n - 2): # O(min(N, 9))
            a += s[i]
            if len(a) > 1 and a[0] == '0':
                break

            if int(a) >= LIM:
                break

            b = ""
            for j in range(i + 1, n - 1): # O(min(N, 9))
                b += s[j]
                
                if len(b) > 1 and b[0] == '0':
                    break

                if int(b) >= LIM:
                    break
                
                res = sim(a, b, j + 1)
                if res != []:
                    return res
        return []

"""
O(9^2 * N)

11 | 235 | 8130

11 235
wanted_value = 11 + 23 = 34

"""