n, m, p = map(int, input().split())
b = True
c = n
for x in map(int, input().split()):
    if x >= n: b = False; break
    d = max((x - c) // 20 + 1, 0)
    if d > p: b = False; break
    c = min(c + d * 20, n) - x
    p -= d
print(['next time', 'champion'][b])
