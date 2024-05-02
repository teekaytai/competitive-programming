n=int(input())
i=1
while n>1:n=[n//2,3*n+1][n%2];i+=1
print(i)
