for _ in range(int(input())):
    x = 0
    for d in input().split(','):
        x = 60*x+(0 if not d else int(d))
    print(x)
