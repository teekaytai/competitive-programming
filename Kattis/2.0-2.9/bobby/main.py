import math
for _ in range(int(input())):
    r,s,x,y,w = map(int, input().split())
    p = sum(math.comb(y,i)*((s-r+1)/s)**i*((r-1)/s)**(y-i) for i in range(x, y+1))
    print(['no','yes'][w>1/p])
