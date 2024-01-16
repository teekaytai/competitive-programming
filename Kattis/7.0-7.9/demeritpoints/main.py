def p(t, s):
    t = str(t)
    print(f'{t[:4]}-{t[4:6]}-{t[6:]}',f'{s} demerit point(s).' if s>0 else f'{-s} merit point(s).' if s<0 else 'No merit or demerit points.')
l, *a = open(0)
T = int(l)
s = 0
p(T, s)
for l in a:
    t, d = map(int, l.split())
    while s > 0 and t >= T + 10000:
        T += 10000
        s = min(s//2, max(s-2, 0))
        p(T, s)
    while s > -5 and t >= T + 20000:
        T += 20000
        s -= 1
        p(T, s)
    T = t
    if s >= 0:
        s += d
    elif d > -2*s:
        s = d + 2*s
    else:
        s += (d+1) // 2
    p(T, s)

while s > 0:
    T += 10000
    s = min(s//2, max(s-2, 0))
    p(T, s)
while s > -5:
    T += 20000
    s -= 1
    p(T, s)
