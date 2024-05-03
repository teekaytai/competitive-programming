n, m = map(int, input().split())
print(['Neibb','Jebb'][len({x for _ in range(n) for x in [int(c) for c in input().split()][1:]})==m])
