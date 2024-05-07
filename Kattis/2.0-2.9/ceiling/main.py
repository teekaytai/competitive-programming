def f(a):
    if not a: return None
    l = []
    r = []
    for i in range(1, len(a)):
        if a[i] < a[0]: l.append(a[i])
        else: r.append(a[i])
    return (f(l), f(r))

n, m = map(int, input().split())
s = set()
for _ in range(n):
    *a, = map(int, input().split())
    s.add(f(a))
print(len(s))
