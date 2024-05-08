for _ in range(int(input())):
    n, *a = map(int, input().split())
    m = sum(a) / n
    print(f'{sum(x>m for x in a)/n:.3%}')
