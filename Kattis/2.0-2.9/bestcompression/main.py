n, b = map(int, input().split())
print(['no','yes'][(1<<b+1)-1>=n])
