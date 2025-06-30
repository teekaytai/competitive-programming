import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    l, r  = map(int, input().split())
    N = min(10000002, r + 1)
    isp = [True] * N
    isp[:2] = [False, False]
    isp2 = [True] * (r - l)
    for i in range(2, N):
        if not isp[i]: continue
        for j in range(i * 2, N, i):
            isp[j] = False
        for j in range((l + i) // i * i, r + 1, i):
            isp2[j - l - 1] = False
        p = i
        while p <= r:
            if p > l: isp2[p - l - 1] = True
            p *= i
    print(1 + sum(isp2))

main()
