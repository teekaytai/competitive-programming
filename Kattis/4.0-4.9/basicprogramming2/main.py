from collections import Counter
N, t = map(int, input().split())
a = [int(x) for x in input().split()]
c = Counter(a)
if t == 1:
    print('Yes' if any(7777-x in c for x in a) else 'No')
elif t == 2:
    print('Unique' if len(c) == N else 'Contains duplicate')
elif t == 3:
    x, v = c.most_common(1)[0]
    print(x if v > N // 2 else -1)
elif t == 4:
    a.sort()
    print(*a[(N-1)//2:(N+2)//2])
else:
    print(*sorted(x for x in a if 100<=x<=999))
