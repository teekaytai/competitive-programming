from collections import Counter
n = int(input())
s = input()
mx = 0
for i in range(n):
    c = Counter()
    for j in range(i, n):
        c[s[j]] += 1
        if len(set(c.values())) == 1:
            mx = max(mx, j-i+1)
print(mx)
