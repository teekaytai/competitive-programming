input()
print(['yes','no'][sum(map(int, input().split()))%3>0])
