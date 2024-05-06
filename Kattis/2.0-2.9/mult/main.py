_, *a = map(int, open(0))
p = 0
for x in a:
    if not p: p = x
    elif x % p == 0: p = 0; print(x)
