import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    s = input()
    k = ''.join(sorted(set(s)))
    print(''.join(k[-k.index(c)-1] for c in s))

tcs = int(input())
for tc in range(tcs):
    main()
