import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [-1, 3] * (n // 2)
    if n % 2 == 0: a[-1] -= 1
    else: a.append(-1)
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
