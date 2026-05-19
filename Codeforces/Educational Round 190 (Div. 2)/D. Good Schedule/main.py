import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    cs = [0] * (n + 2)
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]
    t = 0
    ans = 0
    for a, b in zip(A, B):
        cs[1] += 1
        t += 1
        if a == b:
            cs[a + 1] += cs[a]
            cs[a] = 0
        else:
            t -= cs[a]
            t -= cs[b]
            cs[a] = 0
            cs[b] = 0
        ans += t
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
