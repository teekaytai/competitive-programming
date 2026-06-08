import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = [0] * n
    for i in range(n):
        t = 0
        ds = [0] * n
        j = (i + 1) % n
        while j != i:
            ds[j] = ds[j - 1] if ds[j - 1] > a[j - 1] else a[j - 1]
            j = (j + 1) % n
        j = (i - 1) % n
        while j != i:
            if ds[j] <= a[j]:
                break
            k = (j + 1) % n
            if ds[k] > a[j]:
                ds[j] = ds[k]
            else:
                ds[j] = a[j]
            j = (j - 1) % n
        ans[i] = sum(ds)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
