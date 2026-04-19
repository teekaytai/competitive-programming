import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    input()
    for i in range(2, n+1):
        *a, = map(int, input().split())
        print(i, max(x for x in a if x!=i))

main()
