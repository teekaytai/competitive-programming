import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, a, b = map(int, input().split())
    ans = a
    c = (a + b) % n
    while c != a:
        ans = max(ans, c)
        c = (c + b) % n
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
