import random

n = 50
LOWER_BOUND = -10 ** 8
cur = LOWER_BOUND
a = []

r = list(range(n))
random.shuffle(r)

for x in r:
    a.append(cur)
    cur += x

print(a)
print(len(a))