import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a.sort()
    s = 0
    for i in range(k - 1, -1, -1):
        s += a[i]
        if s >= x:
            print(k - i + n - k)
            break
    else:
        print(-1)

main()
