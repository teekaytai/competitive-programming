from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()

N = 10000002
lastp = [0] * N
for i in range(2, N):
    if i * i > N: break
    if lastp[i]: continue
    for j in range(i * 2, N, i):
        lastp[j] = i

n = int(input())
a = [int(x) for x in input().split()]
pss = []
for i, x in enumerate(a):
    ps = []
    while p := lastp[x]:
        x //= p
        if not ps or ps[-1] != p:
            ps.append(p)
    if x > 1 and (not ps or ps[-1] != x):
        ps.append(x)
    pss.append(ps)
ls = []
rs = []
c = Counter()
for i, ps in enumerate(pss):
    l = 0
    for p in ps:
        l = max(l, c.get(p, -1) + 1)
        c[p] = max(c[p], i)
    ls.append(l)
c = Counter()
for i in range(n - 1, -1, -1):
    ps = pss[i]
    r = n - 1
    for p in ps:
        r = min(r, c.get(p, n) - 1)
        c[p] = min(c.get(p, n), i)
    rs.append(r)
rs.reverse()

ans = [0] * n
st = [(0, n-1, 0)]
while st:
    lo, hi, x = st.pop()
    if lo > hi: continue
    i = lo
    j = hi
    t = True
    while i <= j:
        if t:
            if ls[i] <= lo and hi <= rs[i]:
                st.append((lo, i - 1, i + 1))
                st.append((i + 1, hi, i + 1))
                ans[i] = x
                break
            i += 1
        else:
            if ls[j] <= lo and hi <= rs[j]:
                st.append((lo, j - 1, j + 1))
                st.append((j + 1, hi, j + 1))
                ans[j] = x
                break
            j -= 1
        t = not t
    else:
        print('impossible')
        exit()
print(*ans)
