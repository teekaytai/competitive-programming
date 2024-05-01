h, k, v, s = map(int, input().split())
d = 0
while h > 0:
    v += s
    v -= max(1, v//10)
    h += v>=k
    if 0<v<k:
        h -= 1
        if h == 0: v = 0
    elif v<=0:
        h = v = 0
    d += v
    s -= s > 0
print(d)
