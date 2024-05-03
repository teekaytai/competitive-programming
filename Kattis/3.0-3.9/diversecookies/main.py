n, a, b, c = map(int, input().split())
a, b, c = sorted((a, b, c))
m = min(c, a+b+1)
print(a+b+m+min(c-m,n-1))
