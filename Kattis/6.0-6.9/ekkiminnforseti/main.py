from heapq import *
n, m = map(int, input().split())
names = [input() for _ in range(m)]
votes = [[] for _ in range(m)]
for _ in range(n):
    vs = [int(x)-1 for x in reversed(input().split())]
    votes[vs.pop()].append(vs)
pq = [(len(vs), -i) for i, vs in enumerate(votes)]
heapify(pq)
kicked = [False] * m
kick_count = m - 1
while kick_count:
    l, i = heappop(pq)
    i = -i
    if len(votes[i]) != l:
        continue
    kicked[i] = True
    kick_count -= 1
    while votes[i]:
        vs = votes[i].pop()
        j = vs.pop()
        while kicked[j]:
            j = vs.pop()
        votes[j].append(vs)
        heappush(pq, (len(votes[j]), -j))

winner_id = kicked.index(False)
print(names[winner_id])
