for _ in range(int(input())):
    n = int(input())
    t = []
    for _ in range(n):
        _, *a = map(int, input().split())
        t.append(sum(a))
    t.sort()
    print(sum(x*i for x, i in zip(t, range(n, 0, -1))) / n)
