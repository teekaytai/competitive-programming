import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    M = 2000000
    c = [0] * (2 * M + 1)
    for x in map(int, input().split()):
        c[x] += 2
    dp = 1
    for i, x in enumerate(c):
        if x > 2:
            y = (x - 1) // 2
            c[i * 2] += y
            x -= 2 * y
        for _ in range(x):
            dp |= dp << i
    print(dp.bit_count() // 2 + 1)

main()
