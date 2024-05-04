P = 0
C = ''
d = {}
for _ in range(int(input())):
    x, a = input().split()
    t = int(x)
    for c in a:
        if c in d:
            p = t - d[c]
            if p > P: P = p; C = c
        d[c] = t
print(C)
