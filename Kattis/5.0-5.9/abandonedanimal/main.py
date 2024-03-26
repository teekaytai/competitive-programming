import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
k = int(input())
a = [set() for _ in range(n)]
for _ in range(k):
    i, s = input().split()
    a[int(i)].add(s)
m = int(input())
l = [input() for _ in range(m)]
q = [0]
for S in a:
    q2 = q[:]
    s = input()
    for i in q:
        while i < m and l[i] in S:
            q2.append(i:=i+1)
    *q, = sorted(q2, reverse=True)[:2]
print('ambiguous' if q == [m, m] else 'unique' if m in q else 'impossible')
