n = int(input())
*a, = map(int, input().split())
s = sum(a) // 3
c = 0
i = 0
j = 0
for k, x in enumerate(a):
    if c == s: c = 0; i = j; j = k
    c += x
    if c > s: print(-1); break
else:
    print(i, j)
