n = int(input())
d = float(input())
m = 0
for _ in range(n):
    s, *a = input().split()
    x = d / float(a[1])
    if x > m: m = x; b = s
print(b)
