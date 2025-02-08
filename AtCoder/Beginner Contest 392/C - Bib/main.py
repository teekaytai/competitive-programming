import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    d = {x: i for i, x in enumerate(b)}
    print(*(b[a[d[i]]-1]for i in range(1, n+1)))

# tcs = int(input())
# for tc in range(tcs):
main()
