n = int(input())
a = input().split()
x = 0
s = input()
while s:
    for i, d in enumerate(a):
        if s.startswith(d):
            x = x * n + i
            s = s[len(d):]
print(x)
