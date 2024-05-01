for _ in range(int(input())):
    x = 1
    t = 0
    for y in map(int, input().split()):
        t += max(y-2*x, 0)
        x = y
    print(t)
