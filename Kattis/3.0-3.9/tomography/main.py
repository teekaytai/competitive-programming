from heapq import *
n, m = map(int, input().split())
a = sorted(map(int, input().split()), reverse=True)
b = [-int(x) for x in input().split() if x != '0']
if sum(a) + sum(b) != 0: print('No'); exit()
heapify(b)
for x in a:
    if x > len(b): print('No'); break
    t = [heappop(b) + 1 for _ in range(x)]
    for x in t:
        if x: heappush(b, x)
else: print('Yes')
