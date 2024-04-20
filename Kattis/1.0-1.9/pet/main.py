print(*max(enumerate([sum(map(int,l.split()))for l in open(0)], start=1),key=lambda p:p[1]))
