n, m = map(int, input().split())
a = sorted(map(int, input().split()))
a.append(10000000000)
for i, x in enumerate(a):
    if x >= m: break
    m -= x + 1
print(i)
