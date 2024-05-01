for _ in range(int(input())):
    i, b, n = map(int, input().split())
    t = 0
    while n:
        t += (n % b)**2
        n //= b
    print(i, t)
