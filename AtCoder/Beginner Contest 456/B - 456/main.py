from itertools import product
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a1 = [int(x) for x in input().split()]
    a2 = [int(x) for x in input().split()]
    a3 = [int(x) for x in input().split()]
    t = 0
    for x, y, z in product(a1, a2, a3):
        t += sorted((x, y, z)) == [4, 5, 6]
    print(t / 6**3)

main()
