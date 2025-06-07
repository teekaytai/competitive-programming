from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, l = map(int, input().split())
    if l % 3: print(0); return
    *a, = map(int, input().split())
    D = Counter()
    D[0] = 1
    x = 0
    t = 0
    c = l // 3
    for d in a:
        x = (x + d) % l
        t += D[(x + c) % l] * D[(x + c + c) % l]
        D[x] += 1
    print(t)

main()
