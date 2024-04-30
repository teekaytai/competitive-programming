s = input()
n = int(s)
D = sorted(map(int, s))
P = [0] * 7

def f(n, k):
    if k >= len(D):
        if n: return 0
        r = x = 1
        ld = lp = 0
        cd = cp = -1
        for d, p in zip(D, P):
            if d != cd:
                r *= x
                x = 1
                ld = lp = 1
                cd = d; cp = p
            else:
                ld += 1
                x *= ld
                if p == cp:
                    lp += 1
                    x //= lp
                else:
                    lp = 1
                    cp = p
        return r * x

    d = D[k]
    c = P[k-1] if k > 0 and D[k-1] == d else 1
    t = 0
    while c <= n:
        P[k] = c
        t += f(n - c, k + 1)
        c *= d
    return t

print(f(n, 0))
