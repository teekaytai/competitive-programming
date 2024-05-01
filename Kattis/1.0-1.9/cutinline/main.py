q = [input() for _ in range(int(input()))]
for _ in range(int(input())):
    c, *x = input().split()
    if c == 'cut': q.insert(q.index(x[1]), x[0])
    else: q.remove(x[0])
for x in q:print(x)
