import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    l, r, d, u = [int(x) for x in input().split()]
    ans = 0
    for i in range(l, r + 1):
        if i % 2 == 0:
            ans += max(min(abs(i), u) - max(-abs(i), d) + 1, 0)
        ans += max((u - max(d - 1, abs(i)) + (1 - u % 2)) // 2, 0)
        ans += max((min(u + 1, -abs(i)) - d + (1 - d % 2)) // 2, 0)
    print(ans)

main()
