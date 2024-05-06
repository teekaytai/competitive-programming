n, e = map(int, input().split())
s = str(2**e)
print(sum(s in str(i) for i in range(n+1)))
