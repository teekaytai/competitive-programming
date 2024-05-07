_, *a = map(int, open(0))
c = 0
t = 0
for x in a:
    c += int(x)
    if c < 0: t -= c; c = 0
print(t)
