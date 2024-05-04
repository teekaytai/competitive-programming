for _ in range(int(input())):
    n = int(input())
    p = 0
    t = 0
    for x in map(int, input().split()):
        if x == p + 1: p = x
        else: t += 1
    print(t)
