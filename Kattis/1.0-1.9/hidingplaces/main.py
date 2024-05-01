DIRS = [(-2,1),(-2,-1),(-1,-2),(-1,2),(1,-2),(1,2),(2,-1),(2,1)]

for _ in range(int(input())):
    s = input()
    R = int(s[1]) - 1
    C = ord(s[0]) - 97
    seen = [[False] * 8 for _ in range(8)]
    seen[R][C] = True
    q1 = []
    q2 = [(R, C)]
    d = -1
    while q2:
        q1, q2 = q2, q1
        q2.clear()
        d += 1
        for r, c in q1:
            for dr, dc in DIRS:
                r2 = r+dr
                c2 = c+dc
                if r2<0 or r2>7 or c2<0 or c2>7 or seen[r2][c2]: continue
                seen[r2][c2] = True
                q2.append((r2,c2))
    print(d, *(chr(c+97)+str(r+1) for r,c in sorted(q1, key=lambda p:(-p[0],p[1]))))
