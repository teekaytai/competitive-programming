import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    L, R = map(int, input().split())
    l = L
    r = R
    b = 1 << (r.bit_length() - 1)
    t = 0
    while l & b == r & b:
        t += l & b
        l -= b
        r -= b
        b >>= 1
    x, y = t + b, t + b - 1
    # printerr(t, b)
    z = L if L not in (x,y) else L + 1 if L + 1 not in (x, y) else L + 2
    # printerr((x^y) + (x^z) + (y^z))
    print(x, y, z)

tcs = int(input())
for tc in range(tcs):
    main()
