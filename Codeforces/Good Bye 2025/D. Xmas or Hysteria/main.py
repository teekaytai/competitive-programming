import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    I = sorted(range(n), key=a.__getitem__)
    if m * 2 > n:
        print(-1)
        return
    ans = []
    if m == 0:
        s = 0
        for i in range(n - 2, -1, -1):
            s += a[I[i]]
            if s >= a[I[-1]]:
                break
        else:
            print(-1)
            return
        for j in range(i):
            ans.append((j, j + 1))
        ans.append((i, n - 1))
        for j in range(i + 1, n - 1):
            ans.append((j, n - 1))
    else:
        k = n - 2 * m
        for i in range(k):
            ans.append((i, i + 1))
        for i in range(n - m, n):
            ans.append((i, i - m))
    print(len(ans))
    for l,r in ans: print(I[l] + 1, I[r] + 1)

tcs = int(input())
for tc in range(tcs):
    main()
