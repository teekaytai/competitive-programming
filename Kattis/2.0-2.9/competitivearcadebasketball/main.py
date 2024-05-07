n, p, m = map(int, input().split())
d = {input(): 0 for _ in range(n)}
a = []
for _ in range(m):
    s, v = input().split()
    d[s] += int(v)
    if d[s] >= p and d[s] - int(v) < p: a.append(s)
if not a: print('No winner!')
for s in a:
    print(s, 'wins!')
