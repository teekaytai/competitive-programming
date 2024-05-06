a, b = map(int, input().split())
c, d = map(int, input().split())
t = b - a
x = (c + b - a) % d
while x:
    t += b
    x = (x + b) % d
print(t)
