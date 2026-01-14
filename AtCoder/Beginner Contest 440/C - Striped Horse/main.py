import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, w = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    cs = [0] * (2*w)
    i = 0
    for x in a:
        cs[i] += x
        i += 1
        if i == (2*w): i = 0
    cs += cs
    s = sum(cs[:w])
    ans = s
    for i in range(2*w):
        s += cs[i + w] - cs[i]
        ans = min(ans, s)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
