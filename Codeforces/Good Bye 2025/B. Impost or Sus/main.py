import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = (s[0]!='s') + (s[-1]!='s')
    s = s[1:-1].split('s')
    print(t+sum(len(c) // 2 for c in s))

tcs = int(input())
for tc in range(tcs):
    main()
