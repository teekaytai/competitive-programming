DIRS = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
for _ in range(int(input())):
    sx, sy, tx, ty = input().split()
    sx = ord(sx) - 64
    tx = ord(tx) - 64
    sy = int(sy)
    ty = int(ty)
    if (sx + sy) % 2 != (tx + ty) % 2:
        print('Impossible')
        continue
    q = [((sx, sy),)]
    for p in q:
        if p[-1] == (tx, ty):
            a = [len(p) - 1]
            for x, y in p:
                a.append(chr(x + 64))
                a.append(y)
            print(*a)
            break
        x1, y1 = p[-1]
        for dx, dy in DIRS:
            for i in range(1, 8):
                x2 = x1 + dx * i
                y2 = y1 + dy * i
                if x2 < 1 or x2 > 8 or y2 < 1 or y2 > 8:
                    break
                q.append((*p, (x2, y2)))
