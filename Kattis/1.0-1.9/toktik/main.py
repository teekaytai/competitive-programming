from collections import Counter
c=Counter()
for _ in range(int(input())):
    s, x = input().split()
    c[s] += int(x)
print(c.most_common(1)[0][0])
