for _ in range(int(input())):
    d, m = map(int, input().split())
    c = 6
    t = 0
    for x in map(int, input().split()):
        t += x >= 13 and (c + 13) % 7 == 5
        c = (c + x) % 7
    print(t)
