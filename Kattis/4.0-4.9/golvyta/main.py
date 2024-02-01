n = int(input())
h = []
v = []
for d in input():
    if d in '><': h.append(1 if d == '>' else -1)
    else: v.append(1 if d == 'v' else -1)
r, c = map(int, input().split())
def f(a, x):
    lo = x
    hi = n + 1
    while lo < hi:
        mid = (lo + hi) // 2
        t = 0
        for d in a:
            t = min(max(t + d, 0), mid)
        if t < x:
            lo = mid + 1
        else:
            hi = mid
    return lo + 1 if lo < n + 1 else 0
print(f(h, c) * f(v, r) or -1)
