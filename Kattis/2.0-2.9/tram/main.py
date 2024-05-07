a = []
for _ in range(int(input())):
    x, y = map(int, input().split())
    a.append(y-x)
print(sum(a) / len(a))
