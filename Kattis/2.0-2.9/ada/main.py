_, *a = map(int, input().split())
d = [a]
while not all(x==d[-1][0] for x in d[-1]):
    d.append([y-x for x,y in zip(d[-1], d[-1][1:])])
print(len(d)-1, sum(r[-1] for r in d))
