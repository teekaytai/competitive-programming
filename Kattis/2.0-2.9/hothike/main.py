input()
*a, = map(int, input().split())
print(*min((max(t1, t2), i) for i, (t1, t2) in enumerate(zip(a, a[2:]), start=1))[::-1])
