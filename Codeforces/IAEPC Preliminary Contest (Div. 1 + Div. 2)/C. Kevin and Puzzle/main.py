from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args
MOD = 998244353
def main():
    n = int(input())
    dp = {(0, False): 1}
    for x in map(int, input().split()):
        dp2 = defaultdict(int)
        for (c, b), v in dp.items():
            if b:
                if x == c: dp2[(c, False)] = (dp2[(c, False)] + v) % MOD
            else:
                if x == c: dp2[(c, False)] = (dp2[(c, False)] + v) % MOD
                dp2[(c + 1, True)] = (dp2[(c + 1, True)] + v) % MOD
        dp = dp2
    print(sum(dp.values()) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
