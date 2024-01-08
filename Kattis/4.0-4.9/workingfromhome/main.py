m, p, n = map(int, input().split())
M=m
t=0
for _ in range(n):
    x = int(input())
    t += x >= M
    M = m - (x-M)*p//100
print(t)
