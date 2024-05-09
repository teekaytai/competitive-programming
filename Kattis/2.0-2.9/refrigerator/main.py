a,b,c,d,n = map(int, input().split())
m = 100000000, 0, 0
for i in range((n+b-1)//b+1):
    j = max((n-b*i+d-1)//d, 0)
    m = min(m, (i*a+j*c,i,j))
print(m[1], m[2], m[0])
