import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, x, s = [int(x) for x in input().split()]
    a = 0
    c = 0
    e = x
    ans = 0
    for p in input():
        if p == 'I':
            if e:
                e -= 1
                c += s - 1
                ans += 1
        elif p == 'E':
            if c:
                c -= 1
                ans += 1
            elif a and e:
                a -= 1
                e -= 1
                c += s - 1
                ans += 1
        else:
            if c:
                c -= 1
                a += 1
                ans += 1
            elif e:
                e -= 1
                c += s - 1
                ans += 1
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
