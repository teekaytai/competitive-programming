n, m = map(int, input().split())
*a, = map(int, input().split())
t = 0
for i in range(m):
    t += a[i]
    if t > n:
        break
print(m-i)
