import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    msb = 1 << (n.bit_length() - 1)
    if n % 2 == 0:
        if n >= 8:
            a = [1, 3, msb-2, msb-1, n]
            print(msb*2-1)
            print(*[x for x in range(1, n+1) if x not in a], *a)
        else:
            print(7)
            print(1, 2, 4, 6, 5, 3)
    else:
        if n == msb * 2 - 1:
            a = [1, 3, n-1, n]
            print(n)
            print(*[x for x in range(1, n+1) if x not in a], *a)
        else:
            a = [n - msb, msb - 1, msb, n]
            print(n)
            print(*[x for x in range(1, n+1) if x not in a], *a)


tcs = int(input())
for tc in range(tcs):
    main()
