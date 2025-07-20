import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    t = n * (n + 1) // 2
    b = 1
    while b * b <= n:
        t -= n // b
        b += 1
    while b < n:
        d = n // b
        b2 = min(n, b + (n % b) // d)
        assert n//b2==d and n//(b2+1) < d
        t -= d * (b2 - b + 1)
        b = b2 + 1
    print(t % 998244353)

main()
