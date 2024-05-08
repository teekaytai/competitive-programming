h, s = 0, 0
i = -1
for j in range(1, int(input())+1):
    h2, s2 = map(int, input().split())
    while h > 0:
        h2 -= s
        if h2 <= 0: break
        h -= s2
    else:
        h, s = h2, s2
        i = j
print(i)
