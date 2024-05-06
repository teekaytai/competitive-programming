input()
p = -1
t = 0
for x in sorted(map(int, input().split())):
    if x != p + 1: t += x
    p = x
print(t)
