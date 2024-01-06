tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a=b=float('inf')
    *A, = map(int, input().split())
    if b>a:a,b=b,a
    s=0
    for x in A:
        if x<=b:b=x
        elif x<=a:a=x
        else:b=x;s+=1
        if b>a:a,b=b,a
    print(s)
