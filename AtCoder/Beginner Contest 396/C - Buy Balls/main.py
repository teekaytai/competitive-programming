import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()), reverse=True)
    b = sorted(map(int, input().split()), reverse=True)
    s = 0
    c = 0
    mx = 0
    y = 0
    for i, x in enumerate(a):
        s += x
        if i < len(b):
            c += b[i]
            y = max(y, c)
        mx = max(mx, s + y)
    print(mx)

# tcs = int(input())
# for tc in range(tcs):
main()
