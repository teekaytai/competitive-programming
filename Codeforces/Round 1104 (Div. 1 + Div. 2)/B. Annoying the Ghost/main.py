import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    t = 0
    for i, x in enumerate(b):
        for j in range(i, n):
            if a[j] <= x:
                break
        else:
            print(-1)
            return
        t += j - i
        y = a[j]
        a[i+1:j+1] = a[i:j]
        a[i] = a[j]
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
