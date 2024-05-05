n, m = map(int, input().split())
print(sum(x for _ in range(n) for x in map(int, input().split())) / (n * m))
