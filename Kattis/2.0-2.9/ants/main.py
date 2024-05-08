for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    while len(a) < m: a.extend(map(int, input().split()))
    print(max(min(x, n-x) for x in a), max(max(x, n-x) for x in a))
