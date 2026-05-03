from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    s = input()
    ans = 0
    t = 0
    c = Counter()
    for x in s:
        y = t - c[x] + 1
        ans = (ans + y) % MOD
        c[x] = (c[x] + y) % MOD
        t = (t + y) % MOD
    print(ans)

main()
