input()
n, *a = map(int, input().split())
print(n - len(set(a) - {n}) - 1)
