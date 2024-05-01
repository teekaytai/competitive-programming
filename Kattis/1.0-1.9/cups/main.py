a = []
for _ in range(int(input())):
    x, y = input().split()
    a.append((int(x), y) if x.isdigit() else (int(y)*2, x))
a.sort()
for x, y in a:print(y)
