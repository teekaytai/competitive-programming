tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a=b=c=d=False
    for i in range(n):
        x,y=map(int,input().split())
        a|=x<0
        b|=x>0
        c|=y<0
        d|=y>0
    print('YES'if a+b+c+d<4 else'NO')
