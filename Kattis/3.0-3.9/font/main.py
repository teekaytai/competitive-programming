n = int(input())
s = []
for _ in range(n):
    m = 0
    for c in input():
        m |= 1 << ord(c) - 97
    s.append(m)
A = (1 << 26) - 1
def f(i, m):
    if i == n:
        return m == A
    return f(i+1, m) + f(i+1, m|s[i])
print(f(0, 0))
