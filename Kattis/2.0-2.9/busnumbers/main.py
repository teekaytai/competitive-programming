input()
s, *a = sorted(map(int, input().split()))
a.append(-1)
t = 0
r = []
for x in a:
    if x == t+1 or x == s+1: t = x
    elif t>s+1: r.append((str(s), str(t))); s = x; t = 0
    elif t==s+1: r.append((str(s),)); r.append((str(t),)); s = x; t = 0
    else: r.append((str(s),)); s = x
print(*map('-'.join,r))
