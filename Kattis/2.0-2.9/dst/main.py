for _ in range(int(input())):
    x, *a = input().split()
    d, h, m = map(int, a)
    q, m = divmod(m + d*(1 if x == 'F' else -1), 60)
    h = (h + q) % 24
    print(h, m)
