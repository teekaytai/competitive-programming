from collections import Counter
s = input()
n = len(s)
for i in range(1, n//2+1):
    if n % i: continue
    c = Counter(s[:i])
    if all(Counter(s[j:j+i])==c for j in range(i, n, i)):
        print(s[:i])
        break
else:
    print(-1)
