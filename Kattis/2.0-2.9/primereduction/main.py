*a, _ = map(int, open(0))
def f(x):
    i = 2
    p = []
    while i*i <= x:
        if x % i: i += 1
        else: x //= i; p.append(i)
    p.append(x)
    return p
for x in a:
    i = 1
    while len(p := f(x)) > 1:
        i += 1
        x = sum(p)
    print(x, i)
