import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [input() for _ in range(n)]
    print(len({a[i]+a[j] for i in range(n) for j in range(n) if i != j}))

main()
