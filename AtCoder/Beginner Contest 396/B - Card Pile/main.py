import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = [0] * 100
    for _ in range(n):
        *a, = map(int, input().split())
        if a[0] == 1:
            s.append(a[1])
        else:
            print(s.pop())

# tcs = int(input())
# for tc in range(tcs):
main()
