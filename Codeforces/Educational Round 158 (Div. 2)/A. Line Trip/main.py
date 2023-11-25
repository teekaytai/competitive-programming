t = int(input())
for I in range(t):
    n, x = map(int, input().split())
    a = [0, *(int(x) for x in input().split())]
    print(max(2 * (x - a[-1]), max(y - x for x, y in zip(a, a[1:]))))
