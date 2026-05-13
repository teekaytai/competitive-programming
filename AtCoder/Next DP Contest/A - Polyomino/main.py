import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    dp1 = [0, 0]
    dp2 = [0, 1]
    for i in range(n):
        x = dp2[-2] * 2 + dp1[-1]
        y = dp2[-1] + dp1[-1] + dp2[-2]
        dp1.append(x)
        dp2.append(y)
    print(dp2[-1])

main()
