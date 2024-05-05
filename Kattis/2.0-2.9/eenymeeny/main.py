l = len(input().split())
a = [input() for _ in range(int(input()))]
i = 0
x = []
y = []
for k in range(len(a)):
    i = (i-1+l) % len(a)
    if k%2: y.append(a.pop(i))
    else: x.append(a.pop(i))
print(len(x))
for s in x: print(s)
print(len(y))
for s in y: print(s)
