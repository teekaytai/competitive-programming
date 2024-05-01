while (n:=int(input()))>0:
    p = 0
    t = 0
    for _ in range(n):
        s, q = map(int, input().split())
        t += s * (q-p)
        p = q
    print(t, 'miles')
