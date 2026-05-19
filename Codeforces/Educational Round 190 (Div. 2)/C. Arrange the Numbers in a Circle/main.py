import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    t1 = 0
    t2 = 0
    c2 = 0
    t3 = 0
    a = [int(x) for x in input().split()]
    for x in a:
        if x == 1:
            t1 += 1
        else:
            t2 += x
            c2 += 1
            t3 += max((x - 2) // 2, 0)
    if t2 < 2 or t2 == 2 and t1 == 0:
        print(0)
        return
    if t2 == 2:
        print(3)
        return
    if c2 == 1:
        print(t2 + min(t3 + 1, t1))
    else:
        print(t2 + min(t3, t1))

tcs = int(input())
for tc in range(tcs):
    main()
