n, k = map(int, input().split())
t = 0
c = 0
b = 10
for i in range(1, n + 1):
    if i == b:
        b *= 10
    c = (c * b + i) % k
    t += c == 0
print(t)
