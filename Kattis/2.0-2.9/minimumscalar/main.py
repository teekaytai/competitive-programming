for i in range(1, int(input()) + 1):
    input()
    X = [int(x) for x in input().split()]
    Y = [int(y) for y in input().split()]
    print(f'Case #{i}:', sum(x * y for x, y in zip(sorted(X), sorted(Y, reverse=True))))
