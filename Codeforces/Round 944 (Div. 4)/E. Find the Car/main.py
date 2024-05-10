import bisect
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k, q = map(int, input().split())
    a = [0, *map(int, input().split())]
    b = [0, *map(int, input().split())]
    ans = []
    for _ in range(q):
        d = int(input())
        i = bisect.bisect_left(a, d)
        ans.append(b[i-1]+(b[i]-b[i-1])*(d-a[i-1])//(a[i]-a[i-1]) if i else 0)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
