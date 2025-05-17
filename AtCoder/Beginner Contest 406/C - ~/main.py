import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    c = 0
    pc = 0
    p = a[0]
    t = 0
    for x in a:
        if x > p:
            c += 1
        elif c:
            t += c * pc
            pc = c
            c = 0
        p = x
    print(t + c * pc)

# tcs = int(input())
# for tc in range(tcs):
main()
