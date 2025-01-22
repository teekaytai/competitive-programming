import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    n = int(input())
    a = [0, 0]
    for x in map(int, input().split()):
        a[x%2]+=1
    print(a[1] + (1 if a[0]>0 else -1))

tcs = int(input())
for tc in range(tcs):
    main()
