input()
*a, = map(int, input().split())
s = set(a)
t = sum(a)
print(len(s))
print(*(t-x for x in sorted(s, reverse=True)))
