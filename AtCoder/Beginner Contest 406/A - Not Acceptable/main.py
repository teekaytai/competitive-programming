import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a, b, c, d = map(int, input().split())
    print(['No', 'Yes'][a * 60 + b > c * 60 + d])

# tcs = int(input())
# for tc in range(tcs):
main()
