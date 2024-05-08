p, t = map(int, input().split())
print(sum(sum((s:=input()).istitle() or s.islower() for _ in range(t))==t for _ in range(p)))
