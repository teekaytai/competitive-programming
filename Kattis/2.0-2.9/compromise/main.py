for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [0] * m
    for _ in range(n):
        for i, b in enumerate(input()):
            a[i] += [-1, 1][int(b)]
    print(''.join('1' if x>0 else '0' for x in a))
