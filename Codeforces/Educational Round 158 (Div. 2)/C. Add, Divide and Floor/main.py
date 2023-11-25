t = int(input())
for I in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    mn = min(a)
    mx = max(a)
    b = []
    while mn != mx:
        d = mn % 2
        b.append(d)
        mn = (mn + d) // 2
        mx = (mx + d) // 2
    print(len(b))
    if 0 < len(b) <= n:
        print(*b)
