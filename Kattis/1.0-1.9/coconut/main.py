from collections import deque
s, n = map(int, input().split())
t = n*(n+1)//2
h = [2] * (n+1)
m = n-1
q = deque((i, 0) for i in range(1,n+1))
while m:
    for _ in range(s-1): q.append(q.popleft())
    i, k = q.popleft()
    if k == 0: q.appendleft((i, 1)); q.appendleft((i, 1))
    elif k == 1: q.append((i, 2))
    else:
        h[i] -= 1
        if h[i] == 0:
            t -= i
            m -= 1
print(t)
