c, x, m = map(float, input().split())
ans = ''
for _ in range(6):
    t = input().split()
    s = int(t[0])
    if m / float(t[1]) + m / s * x <= c/2: ans = s
print('YES' if ans else 'NO', ans)
