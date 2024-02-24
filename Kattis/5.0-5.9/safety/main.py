tcs = int(input())
for tc in range(1, tcs+1):
    n, *a = map(int, input().split())
    b = sorted(a, reverse=True)
    T = sum(a)
    res = []
    for x in a:
        t = 2 * T
        c = n
        seen = False
        for y in b:
            if x == y and not seen:
                seen = True
                continue
            m = t / c
            if m < y:
                t -= y
                c -= 1
            else:
                break
        res.append(100*((m - x) / T) if m>x else 0)
    print(f'Case #{tc}:', *res)
