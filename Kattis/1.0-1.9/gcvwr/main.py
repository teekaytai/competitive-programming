a, b, _, *c = map(int, open(0).read().split())
print((a - b) * 9 // 10 - sum(c))
