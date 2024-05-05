from collections import deque
_, *a = map(int, open(0))
for x in a:
    p = deque([x])
    x -= 1
    while x:
        p.appendleft(x)
        for _ in range(x): p.appendleft(p.pop())
        x -= 1
    print(*p)
