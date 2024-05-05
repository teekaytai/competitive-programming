from math import *
m, n, t = map(int, input().split())
print(['TLE','AC'][[0, n<14 and factorial(n) or 1e10, n<31 and 2**n or 1e10, n**4, n**3, n**2, n*log2(n), n][t] <= m])
