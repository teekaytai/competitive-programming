from functools import lru_cache
for _ in range(int(input())):
    k, n, v = map(int, input().split())

    @lru_cache(maxsize=None)
    def f(n, v):
        if v == 0: return 1
        if v >= n: return 0
        if n == 2: return 1
        return (f(n-1, v)*(v+1) + f(n-1, v-1)*(n-v)) % 1001113

    print(k, f(n, v))
