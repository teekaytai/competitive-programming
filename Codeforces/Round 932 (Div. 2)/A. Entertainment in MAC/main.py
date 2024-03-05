import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    tcs = int(input())
    for tc in range(tcs):
        n = int(input())
        s = input()
        print(min(s[::(-1 if n%2 else 1)], s+s[::-1], s[::-1]+s))

main()
