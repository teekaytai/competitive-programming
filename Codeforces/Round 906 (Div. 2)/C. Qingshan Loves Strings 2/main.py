from collections import deque

t = int(input())
for I in range(t):
    n = int(input())
    dq = deque()
    diff = 0
    for c in input():
        diff += 1 if c == '1' else -1
        dq.append(c == '1')
    if diff != 0:
        print(-1)
        continue

    a = []
    lo = 1
    hi = n
    while dq:
        if dq[0] != dq[-1]:
            dq.popleft()
            dq.pop()
            lo += 1
            hi -= 1
        elif not dq[0]:
            a.append(hi)
            dq.popleft()
            dq.append(False)
            lo += 1
            hi += 1
        else:
            a.append(lo - 1)
            dq.pop()
            dq.appendleft(True)
            lo += 1
            hi += 1
    print(len(a))
    print(*a)

