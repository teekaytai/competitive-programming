from itertools import chain
n, m = map(int, input().split())
*a, = sorted(map(int, input().split()), reverse=True)
s = [0] * m
for i, x in zip(chain(range(m), range(m-1, -1, -1)), a):
    s[i] += x
print(max(s))
