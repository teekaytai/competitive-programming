import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a,b=input().split()
    print([4,2,3,1][(a[0]=='s') + 2*(b[0]=='s')])

# tcs = int(input())
# for tc in range(tcs):
main()
