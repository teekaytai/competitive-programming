import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    p = 10 ** k
    c = 1
    for x in a:
        c *= x
        if c >= p:
            c = 1
    print(c)

# tcs = int(input())
# for tc in range(tcs):
main()
