from collections import Counter
a, b = input().split()
s = Counter(a)
print(['FAIL','PASS'][a==''.join(c for c in b if s[c] and not s.subtract(c))])
