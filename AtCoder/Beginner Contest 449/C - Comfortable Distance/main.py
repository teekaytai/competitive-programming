import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    cs = [0] * 200
    n, l, r = [int(x) for x in input().split()]
    s = input()
    ans = 0
    for i, c in enumerate(s):
        o = ord(c)
        if i >= l:
            cs[ord(s[i - l])] += 1
        if i > r:
            cs[ord(s[i - r - 1])] -= 1
        ans += cs[o]
    print(ans)

main()
