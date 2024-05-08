import math
for _ in range(int(input())):
    s = 0
    for _ in range(int(input())):
        x, y = map(int, input().split())
        s += min(10, max(11-(math.ceil((x*x+y*y)**.5)+19)//20, 0))
    print(s)
