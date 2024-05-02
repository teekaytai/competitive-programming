x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
A = x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)
if A < 0: x2,y2,x3,y3 = x3,y3,x2,y2; A=-A
t = 0
for _ in range(int(input())):
    x, y = map(int, input().split())
    p = (y1*x3-x1*y3+(y3-y1)*x+(x1-x3)*y)
    q = (x1*y2-y1*x2+(y1-y2)*x+(x2-x1)*y)
    t += p>=0 and q>=0 and A-p-q>=0
print(f'{A/2:.1f}')
print(t)
