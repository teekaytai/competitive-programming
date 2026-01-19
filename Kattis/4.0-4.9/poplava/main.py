n, x = map(int, input().split())
if x > (n - 1) * (n - 2) // 2:
    print(-1)
else:
    a = [n]
    i = n - 2
    used = [False] * (n - 1)
    while x:
        m = min(x, i)
        y = n - 1 - m
        a.append(y)
        used[y] = True
        x -= m
        i -= 1
    a.append(n - 1)
    a += (i for i in range(n - 2, 0, -1) if not used[i])
    print(' '.join(map(str, a)))
