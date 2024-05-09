a,b,c,d = map(int, input().split())
print(c*d+min(a,b)*(c+d==0)+a*(d>0)+b*(c>0))
