while True:
    n, t = map(int, input().split())
    if not n: break
    for _ in range(t):
        s = input()
        if '/' in s:
            x, _, y = s.split()
            try: print(int(x) * pow(int(y), -1, n) % n)
            except: print(-1)
        else:
            print(eval(s) % n)
