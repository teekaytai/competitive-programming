import sys

input = lambda: sys.stdin.readline().strip()

for _ in range(int(input())):
    n = int(input())
    *p, = map(int, input().split())
    *a, = map(int, input().split())
    mxdp = [0] * n
    mndp = [0] * n
    for i in range(n-1, -1, -1):
        mxdp[i] = a[i] + max(mndp[i+p[i]::p[i]] + [0])
        mndp[i] = a[i] + min(mxdp[i+p[i]::p[i]] + [0])
    print(*mxdp)
