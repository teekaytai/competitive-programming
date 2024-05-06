x, y = map(int, input().split())
print(['up','down'][round(y/x)%2])
