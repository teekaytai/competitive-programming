n = int(input())
*a, = map(int, input().split())
*b, = map(int, input().split())
t = 0
ans = 0
for x, y in sorted(zip(b, a)):
    if x == -1:
        continue
    t += y
    ans = max(ans, (t + x - 1) // x)
print(ans)
