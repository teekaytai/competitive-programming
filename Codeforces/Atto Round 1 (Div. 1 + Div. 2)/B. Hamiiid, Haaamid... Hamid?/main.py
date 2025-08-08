import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    s = input()
    if k == 1 or k == n:
        print(1)
        return
    l = s.rfind('#', end=k)
    r = s.find('#', start=k)
    if l==-1 and r==-1:
        print(1)
    else:
        b = l!=-1 and r!=-1
        if l == -1: l = k - 2
        elif r == -1: r = k
        l += 2
        r = n - r + 1
        if b:
            if l < r: l = k
            else: r = n - k + 1
        print(min(l, r))

tcs = int(input())
for tc in range(tcs):
    main()
