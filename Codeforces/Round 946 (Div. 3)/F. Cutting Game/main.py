from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b, n, m = map(int, input().split())
    A = deque(sorted((*map(int, input().split()),) for _ in range(n)))
    B = deque(sorted(t[::-1] for t in A))
    l, r, L, R = 1, a, 1, b
    s = [0, 0]
    for i in range(m):
        d, k = input().split()
        k = int(k)
        ds = 0
        if d == 'U':
            l += k
            while A and A[0][0] < l:
                ds += L <= A.popleft()[1] <= R
        elif d == 'D':
            r -= k
            while A and A[-1][0] > r:
                ds += L <= A.pop()[1] <= R
        elif d == 'L':
            L += k
            while B and B[0][0] < L:
                ds += l <= B.popleft()[1] <= r
        else:
            R -= k
            while B and B[-1][0] > R:
                ds += l <= B.pop()[1] <= r
        s[i%2] += ds
    print(*s)

tcs = int(input())
for tc in range(tcs):
    main()
