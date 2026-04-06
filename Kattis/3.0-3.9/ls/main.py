p = input()
for _ in range(int(input())):
    s = input()
    x = -1
    q = [0]
    for c in s:
        if q and q[-1] == len(p):
            q.pop()
        if not q:
            break
        if p[q[-1]] == '*':
            x = q[-1] + 1
            while x < len(p) and p[x] == '*':
                x += 1
            q = [x]
            if x == len(p):
                break
        q2 = [x] * (x != -1)
        for y in q:
            if p[y] == c:
                q2.append(y + 1)
        q = q2
    if q and q[-1] == len(p):
        print(s)
