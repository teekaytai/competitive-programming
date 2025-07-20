from itertools import product
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def g():
    l = 1
    while True:
        for d in range(1, 10):
            for p in product(range(10), repeat=(l-1)//2):
                t = d
                for x in p:
                    t = t * 10 + x
                for i in range(len(p) - 1 - l%2, -1, -1):
                    t = t * 10 + p[i]
                if l > 1:
                    t = t * 10 + d
                yield t
        l += 1

def main():
    a = int(input())
    n = int(input())
    t = 0
    for x in g():
        if x > n:
            break
        ds = []
        y = x
        while x:
            ds.append(x % a)
            x //= a
        if ds == ds[::-1]: t += y
    print(t)

main()
