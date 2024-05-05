import sys

input = lambda: sys.stdin.readline().strip()

N = 2000001
fs = [-1] * N
for i in range(2, N):
    if fs[i] != -1: continue
    fs[i] = i
    for j in range(i * 2, N, i):
        fs[j] = i

for _ in range(int(input())):
    x = int(input())
    p = -1
    c = 0
    r = 1
    t = 0
    while x > 1:
        if fs[x] == p:
            c += 1
        else:
            r *= c + 1
            p = fs[x]
            t += 1
            c = 1
        x //= p
    print(r * (c+1) - t)
