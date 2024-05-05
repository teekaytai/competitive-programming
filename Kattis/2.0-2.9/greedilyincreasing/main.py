input()
a = []
for x in map(int, input().split()):
    if not a or x > a[-1]: a.append(x)
print(len(a))
print(*a)
