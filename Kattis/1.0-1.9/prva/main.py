h, w = map(int, input().split())
g = [input() for _ in range(h)]
a = [*(x for l in g for x in l.split('#')), *(x for l in zip(*g) for x in ''.join(l).split('#'))]
print(min(x for x in a if len(x) > 1))
