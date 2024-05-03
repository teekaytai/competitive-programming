for _ in range(int(input())):
    n, m = map(int, input().split())
    *a, = map(int, input().split())
    p = 0
    c = 0
    b = False
    mx = 0
    for x in a:
        if x == m:
            if b: mx = max(mx, p + c + m)
            b = True
            p = c
            c = 0
        elif x < m:
            if b: mx = max(mx, p + c + m)
            b = False
            p = c = 0
        else:
            c += x
    if b: mx = max(mx, p + c + m)
    print(mx)
