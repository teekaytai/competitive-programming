n = int(input())
x = int(input())
y = int(input())
a = sorted(map(int, input().split()))
t = 0
s = 0
for v in a:
    s += x * v
    if s / (t + 1) > y: break
    t += 1
print(t)
