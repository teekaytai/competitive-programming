import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    i = s.find(')(')
    if i == -1:
        print(-1)
        return
    j = s.find('(', i + 2)
    print(n - 2 if j != -1 else -1)

tcs = int(input())
for tc in range(tcs):
    main()
