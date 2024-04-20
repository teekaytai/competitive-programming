t = 0
for s in input().split(';'):
    a, *b = map(int, s.split('-'))
    t += b[0] - a + 1 if b else 1
print(t)
