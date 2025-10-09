import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    w = n
    l = 0
    t = 1
    while w >= 2 or l >= 2:
        t += w//2 + l//2
        w, l = (w+1)//2, (l+1)//2+w//2
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
