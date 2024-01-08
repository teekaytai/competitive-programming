from collections import deque
import sys
input = lambda: sys.stdin.readline().strip()
n = int(input())
l = deque()
r = deque()
for _ in range(n):
    o, x = input().split()
    x = int(x)
    if o == 'push_back':
        r.append(x)
        if len(r) > len(l):
            l.append(r.popleft())
    elif o == 'push_front':
        l.appendleft(x)
        if len(l) > len(r) + 1:
            r.appendleft(l.pop())
    elif o == 'push_middle':
        if len(l) > len(r):
            r.appendleft(x)
        else:
            l.append(x)
    else:
        print(l[x] if x < len(l) else r[x - len(l)])
