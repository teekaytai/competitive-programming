import math
while True:
    d, n = map(float, input().split())
    if d + n == 0: break
    p = []
    for i in range(int(n)):
        x, y = map(float, input().split())
        p.append((x, y))
    s = sum(sum(math.dist(p1, p2)<=d for p2 in p) > 1 for p1 in p)
    print(s, 'sour,', int(n)-s, 'sweet')
