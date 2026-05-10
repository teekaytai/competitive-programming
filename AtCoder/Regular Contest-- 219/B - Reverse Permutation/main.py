import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    t = 0
    for i in range(n):
        if a[i] != i + 1:
            break
        t += n - i - 1
    else:
        t += 1
    print(t % 998244353)

tcs = int(input())
for tc in range(tcs):
    main()
