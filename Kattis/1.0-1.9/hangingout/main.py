l,n = map(int, input().split())
t=0
c=0
for _ in range(n):
    s, x = input().split()
    x = int(x)
    if s == 'enter':
        if c + x > l: t += 1
        else: c += x
    else: c -= x
print(t)
