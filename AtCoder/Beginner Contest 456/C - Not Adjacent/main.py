import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    s = input()
    ans = 0
    l = 1
    for x, y in zip(s, s[1:]):
        if x == y:
            ans = (ans + l * (l + 1) // 2) % MOD
            l = 1
        else:
            l += 1
    ans = (ans + l * (l + 1) // 2) % MOD
    print(ans)

main()
