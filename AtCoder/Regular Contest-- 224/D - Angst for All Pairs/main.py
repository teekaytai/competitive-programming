from math import comb
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    ans = 0
    k -= 1
    l = len(str(k))
    p10 = 10 ** (l - 1)
    for i in range(1, n + 1):
        c = comb(n, i)
        for _ in range(c):
            ans += l * i
            if k == p10:
                l -= 1
                p10 //= 10
            k -= 1
            if k == 0:
                print(ans)
                return
    print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
