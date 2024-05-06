l, n = map(int, input().split())
t = 1
while l % n != 0:
    n = -l % n
    t += 1
print(t)
