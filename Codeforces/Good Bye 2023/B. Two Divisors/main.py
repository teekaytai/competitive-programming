from math import lcm
tcs = int(input())
for tc in range(tcs):
    a,b = map(int,input().split())
    if b%a==0:
        print(b*b//a)
    else:
        print(lcm(a,b))
