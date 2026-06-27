from functools import reduce
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    if n == 1:
        print(0)
        return
    X = reduce(int.__xor__, a)
    ans = int(X == 0)
    if X != 0:
        for v in a:
            y = X ^ v
            if y <= v:
                ans += 1
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
