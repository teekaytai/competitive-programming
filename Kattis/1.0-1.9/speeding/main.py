n=int(input())
t,d=map(int,input().split())
m=0
for _ in range(n-1):
    t2,d2 = map(int, input().split())
    m = max(m, (d2-d)//(t2-t))
    t=t2;d=d2
print(m)
