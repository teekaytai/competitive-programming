from heapq import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))
    b = sorted(map(int, input().split()))
    pqa = [a[i] - a[-1-i] for i in range(n // 2)]
    pqb = [b[i] - b[-1-i] for i in range(m // 2)]
    sa = []
    sb = []
    heapify(pqa)
    heapify(pqb)
    ans = []
    x = 0
    while n + m > 2:
        if not n:
            if not sa: break
            x += sa[-1]
            heappush(pqa, sa.pop())
            v = heappop(pqb)
            sb.append(v)
            x -= v
            n += 1
            m -= 1
        if not m:
            if not sb: break
            x += sb[-1]
            heappush(pqb, sb.pop())
            v = heappop(pqa)
            sa.append(v)
            x -= v
            n -= 1
            m += 1
        if m < 2 or n >= 2 and pqa and pqa[0] < pqb[0]:
            v = heappop(pqa)
            sa.append(v)
            x -= v
            n -= 2
            m -= 1
        else:
            v = heappop(pqb)
            sb.append(v)
            x -= v
            m -= 2
            n -= 1
        ans.append(x)
    print(len(ans))
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
