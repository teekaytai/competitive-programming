n, s, r = map(int, input().split())
a = sorted(map(int, input().split()))
b = set(map(int, input().split()))
i = 0
j = 0
c = []
for x in a:
    if x in b: b.discard(x)
    else: c.append(x)
t = len(c)
for x in c:
    if x-1 in b: b.discard(x-1); t -= 1
    elif x+1 in b: b.discard(x+1); t -= 1
print(t)
