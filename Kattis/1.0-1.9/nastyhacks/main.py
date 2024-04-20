for _ in range(int(input())):
    a, b, c = map(int, input().split())
    x = b - a - c
    print(['does not matter', 'advertise', 'do not advertise'][x and x//abs(x)])
