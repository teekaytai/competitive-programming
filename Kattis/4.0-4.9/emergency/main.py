n, k = map(int, input().split())
if n < 2*k: print(n-1)
else: print(k+1+(n-1)%k)
