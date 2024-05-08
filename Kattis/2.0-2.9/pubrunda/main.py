b = ''
m = 0
for _ in range(int(input())):
    s, *a = input().split()
    t = (int(a[0])+1) * int(a[1])
    if t > m: m = t; b = s
print(b, m)
