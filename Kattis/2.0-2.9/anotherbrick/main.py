h, w, n = map(int, input().split())
*a, = map(int, input().split())
c = 0
for x in a:
    c += x
    if c == w:
        h -= 1; c = 0
        if h == 0: print('YES'); break
    if c > w: print('NO'); break
else:
    print('NO')
