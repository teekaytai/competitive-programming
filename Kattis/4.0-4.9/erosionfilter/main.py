from itertools import accumulate
n = int(input())
*a, = map(int, input().split())
f = lambda t, x: (t + x) / 2
p = [*accumulate(a, f, initial=0)]
s = [*accumulate(a[::-1], f, initial=0)][-2::-1]
print(*map(sum, zip(a, p, s)))
