input()
a = b = 0
for x in map(int, input().split()):
    a, b = min(a, b) + x, a
print(min(a, b))
