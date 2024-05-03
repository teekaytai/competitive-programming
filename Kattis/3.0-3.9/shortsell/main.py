n, k = map(int, input().split())
*a, = map(int, input().split())
mx = 0
c = 0
for x in a:
    mx = max(mx, c-100*x-k)
    c = max(c, 100*x) - k
print(mx)
