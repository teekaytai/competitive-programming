n, s = map(int, input().split())
p = 0
t = 0
for _ in range(n):
    d, r, g = map(int, input().split())
    t += d-p
    p = d
    m = max(r-t%(r+g), 0)
    t += m
    s += m
print(s)
