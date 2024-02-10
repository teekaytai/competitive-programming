from functools import lru_cache
import sys
sys.setrecursionlimit(10000)

n = int(input())
a = [int(input()) for _ in range(n)]

@lru_cache(maxsize=None)
def f(v, d):
    if v == n - 1: return a[-1]
    ans = float('inf')
    if v >= d: ans = min(ans, f(v - d, d))
    if v < n - d - 1: ans = min(ans, f(v + d + 1, d + 1))
    return a[v] + ans

print(f(1, 1))
