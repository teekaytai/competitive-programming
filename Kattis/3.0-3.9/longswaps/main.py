s, n = input().split()
n = int(n)
t = sorted(s)
print(['No', 'Yes'][all(s[i] == t[i] for i in range(len(s) - n, n))])
