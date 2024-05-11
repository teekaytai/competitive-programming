n, m = map(int, input().split())
print((5*pow(2,n-1,m)-1)%m if n else 2%m)
