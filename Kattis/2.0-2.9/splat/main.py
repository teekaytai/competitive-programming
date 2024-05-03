import math
for _ in range(int(input())):
    n = int(input())
    p = []
    for _ in range(n):
        *a, s = input().split()
        p.append((*map(float, a), s))
    for _ in range(int(input())):
        X, Y = map(float, input().split())
        for x, y, v, s in reversed(p):
            if ((X-x)**2+(Y-y)**2)*math.pi<=v:
                print(s)
                break
        else:
            print('white')
