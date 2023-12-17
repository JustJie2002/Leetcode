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