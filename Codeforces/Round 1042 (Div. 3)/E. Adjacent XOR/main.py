import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    print(['NO', 'YES'][a[-1] == b[-1] and all(a[i] == b[i] or a[i] ^ a[i + 1] == b[i] or a[i] ^ b[i + 1] == b[i] for i in range(n - 1))])

tcs = int(input())
for tc in range(tcs):
    main()
