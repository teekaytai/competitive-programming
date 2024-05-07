n, m, *a = map(int, open(0).read().split())
s = set(a)
for i in range(n):
    if i not in s: print(i)
print(f'Mario got {len(s)} of the dangerous obstacles.')
