import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    a = input()
    b = input()
    cs = [0, 0, 0, 0]
    for x, y in zip(a, b):
        cs[2 * int(x) + int(y)] += 1
    d = [0, 0, 0]
    d[0] = cs[2] + cs[3]
    d[1] += cs[1] + cs[2] * (k % 2 == 1) + cs[3] * (k % 2 == 0)
    d[2] += cs[1] + cs[2] * (k % 2 == 0) + cs[3] * (k % 2 == 1)
    for i in range(3):
        d[i] = d[i] * (n - d[i])
    m = 2 ** k + 1
    print(sum(d) * (m // 3) + sum(d[:m % 3]))

tcs = int(input())
for tc in range(tcs):
    main()
