import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    for x,y, z in zip(a, a[1:],a[2:]):
        if x==y==z:
            print('Yes')
            break
    else:
        print('No')

# tcs = int(input())
# for tc in range(tcs):
main()
