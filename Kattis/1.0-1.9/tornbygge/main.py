input()
c = 0
t = 0
for x in map(int, input().split()):
    t += x > c
    c = x
print(t)
