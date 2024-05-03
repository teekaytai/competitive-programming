n = int(input())
a = []
i = 1
while i <= n:
    a.append(i)
    i*=2
print(len(a))
print(*a)
