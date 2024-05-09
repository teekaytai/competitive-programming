from itertools import chain
a = 0
b = 0
for _ in range(int(input())):
    w, h, n = map(int, input().split())
    g = [input() for _ in range(h)]
    def d1(i):
        l = []
        if i < w:
            j = i
            i = 0
        else:
            i -= w - 1
            j = w - 1
        while i < h and j >= 0:
            l.append(g[i][j])
            i += 1; j -= 1
        return l
    def d2(i):
        l = []
        if i < w:
            j = i
            i = h - 1
        else:
            i = h - (i - w) - 1
            j = w - 1
        while i >= 0 and j >= 0:
            l.append(g[i][j])
            i -= 1; j -= 1
        return l
    *l, = map(''.join, chain(g, zip(*g), [d1(i) for i in range(h+w-1)], [d2(i) for i in range(h+w-1)]))
    if any('x'*n in s for s in l): a += 1
    elif any('o'*n in s for s in l): b += 1
print(f'{a}:{b}')
