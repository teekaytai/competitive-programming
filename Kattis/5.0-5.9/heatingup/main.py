import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
*a, = map(int, input().split())
*s, = a
m = [-1] * n
p = [n-1, *range(n-1)]
q = [*range(1, n), 0]
pq = sorted(range(n), key=a.__getitem__)
for i in pq:
    x = a[i]
    m[i] = x
    if m[p[i]] >= 0:
        m[p[i]] = max(m[p[i]], x - s[p[i]])
        m[i] = min(m[i], m[p[i]])
        s[i] += s[p[i]]
        p[i] = p[p[i]]
        q[p[i]] = i
    if m[q[i]] >= 0:
        m[q[i]] = max(m[q[i]], x - s[q[i]])
        m[i] = min(m[i], m[q[i]])
        s[i] += s[q[i]]
        q[i] = q[q[i]]
        p[q[i]] = i
print(m[pq[-1]])
