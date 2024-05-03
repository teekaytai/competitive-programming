_, *a = map(int, open(0))
mx = 0
l = 0
r = sum(a)
p = 0
for x in a:
    p -= l * x
    r -= x
    l += x * x
    p += x * x * r
    mx = max(mx, p)
print(mx)
