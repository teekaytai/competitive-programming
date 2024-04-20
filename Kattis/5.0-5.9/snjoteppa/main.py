n, k = map(int, input().split())
a = [[0, *(c == 'o' for c in input()), 0]for _ in range(2)]
t = sum(a[0][y] * (a[1][y-1] + a[1][y] + a[1][y+1]) for y in range(1, n+1))
for _ in range(k):
    s, *p = input().split()
    if s == 'Q':
        print(['Neibb', 'Jebb'][t == 0])
    else:
        x, y = map(int, p)
        x -= 1
        X = 1 - x
        t += [1, -1][a[x][y]] * (a[X][y] + a[X][y-1] + a[X][y+1])
        a[x][y] = 1 - a[x][y]
