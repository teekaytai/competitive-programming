from collections import Counter

n, k = map(int, input().split())
cs = [Counter(input().split()[1:]) for _ in range(n)]
def f(i, c, v):
    if v == 0: return 1
    if i + v > len(cs): return 0
    t = f(i + 1, c, v)
    c += cs[i]
    if all(c[w] * 2 <= k for w in cs[i]):
        t += f(i + 1, c, v - 1)
    c -= cs[i]
    return t
print(f(0, Counter(), k))
