from itertools import combinations
for tc in range(1, int(input())+1):
    n, *a = map(int, input().split())
    def f():
        d = {}
        for i in range(1, n):
            for c in combinations(a, i):
                s = sum(c)
                if s in d: print(*d[s]); print(*c); return
                d[s] = c
        print('Impossible')
    print(f'Case #{tc}:')
    f()
