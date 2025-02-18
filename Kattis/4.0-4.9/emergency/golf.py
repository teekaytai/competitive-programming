n,k=map(int,input().split())
print(min(n-1,k+1+~-n%k))