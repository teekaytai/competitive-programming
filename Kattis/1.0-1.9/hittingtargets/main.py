n = int(input())
r = []
c = []
for _ in range(n):
    s, *t = input().split()
    t = [int(x) for x in t]
    if s[0]=='r':r.append(t)
    else:c.append(t)
for _ in range(int(input())):
    x, y = map(int, input().split())
    print(sum(x1<=x<=x2 and y1<=y<=y2 for x1,y1,x2,y2 in r) + sum((X-x)**2+(Y-y)**2<=R*R for X,Y,R in c))
