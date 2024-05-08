r, b = map(int, input().split())
p = r + b
s = r//2 + 2
d = int((s*s-4*p)**.5)
print((s+d)//2, (s-d)//2)
