from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = [int(x) for x in input()]
    t = [int(x) for x in input()]
    if s[0] != t[0] or s[-1] != t[-1]:
        print(-1)
        return
    ps = [0] * n
    q = deque([i + 2 for i in range(n - 2) if s[i] == s[i + 2]])
    ans = 0
    for i in range(1, n - 1):
        s[i] ^= ps[i]
        if i < n - 1: ps[i + 1] ^= ps[i]
        if s[i] == t[i]: continue
        while q and q[0] <= i:
            q.popleft()
        if not q:
            print(-1)
            return
        x = q.popleft()
        ans += x - i
        s[i] ^= 1
        ps[i + 1] ^= 1
        ps[x] ^= 1
        if q and q[0] == x + 1:
            q.popleft()
        elif x < n - 1:
            q.appendleft(x + 1)
        # printerr(ans, q)
    # printerr(s)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()

# k = 6
# print(', '.join(f'{i*2:0{k+2}b}' for i in range(1 << k)))
# for i in range(1 << k):
#     for j in range(i):
#         b = i ^ j
#         if b.bit_count() != 1:
#             continue
#         if ((i & (b << 1)) > 0) == ((i & (b >> 1)) > 0):
#             print(f'{i*2:0{k+2}b} -- {j*2:0{k+2}b}')
