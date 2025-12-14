import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    g = set()
    t=0
    for i in range(m):
        r, c = map(int, input().split())
        a = [(r, c), (r+1,c), (r,c+1),(r+1,c+1)]
        if all(x not in g for x in a):
            for x in a:
                g.add(x)
            t+=1
    print(t)

main()
