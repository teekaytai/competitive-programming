import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    s = input()
    if n < k * 2:
        print(-1)
        return
    print(sum(c == 'L' for c in s[:k]) + sum(c == 'R' for c in s[-k:]))

tcs = int(input())
for tc in range(tcs):
    main()
