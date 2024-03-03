MSB = lambda x: 1 << (x.bit_length() - 1)
for _ in range(int(input())):
    n = int(input())
    *a, = map(int, input().split())
    res = [0] * n
    t = 0
    for x, i in sorted(((x, i) for i, x in enumerate(a)), reverse=True):
        r = 0
        while x:
            b = MSB(x)
            if not (t & b):
                r |= b
                t |= b
                x -= b
            else:
                r |= ~t & (b-1)
                t |= b - 1
                break
        res[i] = r
    print(t)
    print(*res)
