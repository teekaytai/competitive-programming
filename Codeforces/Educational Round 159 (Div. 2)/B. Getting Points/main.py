tcs = int(input())
for tc in range(tcs):
    n, p, l, t = map(int, input().split())
    w = (n + 6) // 7
    x = 2 * t + l
    y = w * t + (w + 1) // 2 * l
    if p <= y:
        print(n - (p + x - 1) // x)
    else:
        print(n - ((w + 1) // 2 + (p - y + l - 1) // l))
