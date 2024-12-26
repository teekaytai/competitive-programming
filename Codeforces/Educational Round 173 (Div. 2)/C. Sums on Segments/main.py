import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    p = next((i for i, x in enumerate(a) if abs(x) != 1), 0)
    s = 0
    mxs1 = 0
    mns1 = 0
    mx1 = 0
    mn1 = 0
    cx1 = 0
    cn1 = 0
    for i in range(p-1, -1, -1):
        s += a[i]
        mxs1 = max(mxs1, s)
        mns1 = min(mns1, s)
        cx1 = max(cx1 + a[i], 0)
        cn1 = min(cn1 + a[i], 0)
        mx1 = max(mx1, cx1)
        mn1 = min(mn1, cn1)
    s = 0
    mxs2 = 0
    mns2 = 0
    mx2 = 0
    mn2 = 0
    cx2 = 0
    cn2 = 0
    for i in range(p+1, n):
        s += a[i]
        mxs2 = max(mxs2, s)
        mns2 = min(mns2, s)
        cx2 = max(cx2 + a[i], 0)
        cn2 = min(cn2 + a[i], 0)
        mx2 = max(mx2, cx2)
        mn2 = min(mn2, cn2)
    ans = sorted({*range(mn1, mx1+1), *range(mn2, mx2+1), *range(a[p] + mns1 + mns2, a[p] + mxs1 + mxs2 + 1)})
    print(len(ans))
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
