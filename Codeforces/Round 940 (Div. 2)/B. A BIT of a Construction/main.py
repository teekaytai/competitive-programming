import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    if n == 1:print(k)
    else:
        if k == (1 << k.bit_length()) - 1:
            print(k, *[0]*(n-1))
        else:
            x = (1 << k.bit_length()-1) - 1
            print(x, k-x, *[0]*(n-2))

tcs = int(input())
for tc in range(tcs):
    main()
