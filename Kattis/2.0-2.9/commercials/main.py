n, k = map(int, input().split())
*a, = map(int, input().split())
mx = a[0] - k
c = 0
for x in a:
    c = max(c + x, x) - k
    mx = max(mx, c)
print(mx)
