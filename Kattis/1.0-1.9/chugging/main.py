n=int(input())
ta,da = map(int, input().split())
a = ta*n+da*n*(n-1)//2
tb,db = map(int, input().split())
b = tb*n+db*n*(n-1)//2
print(['Alice','Bob','='][(b==a)+(b<=a)])
