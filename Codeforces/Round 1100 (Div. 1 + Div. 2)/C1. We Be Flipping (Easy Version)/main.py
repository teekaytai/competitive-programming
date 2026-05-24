import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = 1
    ans = []
    for i in range(n - 1, -1, -1):
        if b * a[i] < 0:
            continue
        ans.append(i + 1)
        b = -b
    print(len(ans))
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
