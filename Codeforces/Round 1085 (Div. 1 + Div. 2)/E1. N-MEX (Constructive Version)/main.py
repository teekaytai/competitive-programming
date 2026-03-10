import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    if any(a[i] < n - i - 1 or a[i] > n for i in range(n)) or any(a[i] < a[i + 1] for i in range(n - 1)):
        print('NO')
        return
    print('YES')
    ds = [x - (n - i - 1) for i, x in enumerate(a)]
    st = [(0, -1)]
    ans = []
    p = 10000000, 0
    for d, x in zip(reversed(ds), reversed(a)):
        if d > p[0]:
            st.append(p)
        elif d and d <= st[-1][0]:
            st.pop()
        if d == 0:
            ans.append(100000000)
        else:
            ans.append(st[-1][1] + d - st[-1][0])
        p = d, x
    print(*reversed(ans))

tcs = int(input())
for tc in range(tcs):
    main()
