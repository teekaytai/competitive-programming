import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    s = set(map(int, input().split()))
    a = [i for i in range(1, 1+n) if i not in s]
    print(len(a))
    print(*a)

# tcs = int(input())
# for tc in range(tcs):
main()
