input()
a = sorted(map(int, input().split()))
print(sum((y-x)**2 for x,y in zip(a, a[1:])))
