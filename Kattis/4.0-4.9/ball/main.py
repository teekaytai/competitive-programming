n = int(input())
s = [False] * (n+1)
a = []
for _ in range(n // 2 + 1):
    for x in map(int, input().split()):
        if s[x]: a.append(x)
        else: s[x] = True
print(*sorted(a))
