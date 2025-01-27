n, m = map(int, input().split())
e = []
for _ in range(m):
    x, y = map(int, input().split())
    e.append((x - 1, 1))
    e.append((y, -1))
e.sort()
t = 0
c = 0
p = 0
for x, d in e:
    t += (c > 0) * (x - p)
    p = x
    c += d
print(t)
print(['The Mexicans are Lazy! Sad!', 'The Mexicans took our jobs! Sad!'][t > n/2])
