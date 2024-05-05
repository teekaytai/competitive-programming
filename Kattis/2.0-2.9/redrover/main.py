s = input()
n = len(s)
mn = n
for i in range(n):
    for j in range(i):
        k = s[j:i]
        mn = min(mn, n - s.count(k)*(len(k)-1) + len(k))
print(mn)
