from functools import lru_cache
q, n, d = map(int, input().split())
s1 = input()
s2 = input()
@lru_cache(maxsize=None)
def f(i, k):
    if i >= n: return k == 0
    if s1[i] == s2[i]:
        return (q-1)*f(i+1, k-2) + f(i+1, k)
    return (q-2)*f(i+1, k-2) + 2*f(i+1, k-1)
print(f(0, d))
