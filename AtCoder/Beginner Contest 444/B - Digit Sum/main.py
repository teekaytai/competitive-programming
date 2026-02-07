import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    t = 0
    for i in range(1, n + 1):
        t += sum(map(int, str(i))) == k
    print(t)

main()
