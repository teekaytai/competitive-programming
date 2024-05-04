v, *a = input().split('+')
s = set()
for i in range(1 << len(a)):
    t = 0
    p = v
    for x, b in zip(a, f'{i:0{len(a)}b}'):
        if b == '0': p += x
        else: t += int(p); p = x
    s.add(t + int(p))
print(len(s))
