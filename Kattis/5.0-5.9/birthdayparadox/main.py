from collections import Counter
from math import log10
n, *a = map(int, open(0).read().split())
c = Counter(a)
s = sum(a)
logfacs = [0.0]
for i in range(1, max(366, s + 1)):
    logfacs.append(logfacs[-1] + log10(i))
ans = logfacs[365] - logfacs[365 - n] + logfacs[s] - sum(logfacs[v] for v in c.values()) - sum(logfacs[x] for x in a) - log10(365) * s
print(ans)
