from functools import lru_cache
from itertools import accumulate
import sys
sys.setrecursionlimit(1000000)

input = lambda: sys.stdin.readline().strip()

MOD = 1000003233
n = int(input())
*facs, = accumulate(range(1, 2*n+1), lambda x,y:x*y%MOD,initial=1)
@lru_cache(maxsize=None)
def f(i):
    return 2 * i * (facs[2*i-2] + (2*i-1) * f(i-1)) % MOD if i > 1 else 2

print(f(n) * facs[2*n] % MOD)
