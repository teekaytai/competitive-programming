input()
t = 0
s = 0
for c in reversed(input()):
    if c == 'S':
        s += 1
        if s == 3: print(-1); break
    elif c == '?':
        s = max(s - 1, 0)
    t += 1 + (s > 0)
else:
    print(t - 1 - (s > 0))
