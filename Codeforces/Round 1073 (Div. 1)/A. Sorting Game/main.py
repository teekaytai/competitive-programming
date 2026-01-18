import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = list(input())
    t = sorted(s)
    if s == t:
        print('Bob')
    else:
        c = s.count('0')
        ans = []
        for i in range(c):
            if s[i] != '0':
                ans.append(i + 1)
        for i in range(c, n):
            if s[i] != '1':
                ans.append(i + 1)
        print('Alice')
        print(len(ans))
        print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
