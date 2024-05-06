for _ in range(int(input())):
    input()
    n, m = map(int, input().split())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    x = sum(a)/n
    y = sum(b)/m
    print(sum(y<v<x for v in a))
