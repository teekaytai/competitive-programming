t = 0
for r in range(4):
    for c, l in enumerate(input()):
        if l == '.':
            continue
        idx = ord(l) - 65
        t += abs(idx // 4 - r) + abs(idx % 4 - c)
print(t)
