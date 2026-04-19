import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    MOD = 1000003233
    n = int(input())
    if n == 1: print(3)
    elif n%2 == 1: print(pow(2, n - 1, MOD) * 3 % MOD)
    else: print(pow(2, n - 2, MOD) * 3 % MOD)

main()
