O = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 '
n = int(input())
m = [[int(x) for x in input().split()] for _ in range(n)]
s = input()
s += ' ' * (-len(s)%n)
a = []
for i in range(0, len(s), n):
    x = [O.index(c) for c in s[i:i+n]]
    for r in m:
        a.append(sum(p*q for p,q in zip(x, r))%37)
print(''.join(O[k] for k in a))
