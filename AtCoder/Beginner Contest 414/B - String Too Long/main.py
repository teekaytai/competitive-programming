import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = []
    t = 0
    for _ in range(n):
        c, l = input().split()
        l = int(l)
        t += l
        a.append((c, l))
    print('Too Long' if t > 100 else ''.join(c * l for c, l in a))

main()
