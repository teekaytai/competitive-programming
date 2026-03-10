import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = list(input())
    t = 0
    l = 0
    y = 0
    for i, c in enumerate(s):
        if i > 0 and i < n - 1 and c == '0' and s[i - 1] == s[i + 1] == '1':
            s[i] = '1'
        t += s[i] == '1'
    for c in s:
        if c == '1':
            l += 1
        else:
            y += max((l - 1) // 2, 0)
            l = 0
    y += max((l - 1) // 2, 0)
    print(t - y, t)

tcs = int(input())
for tc in range(tcs):
    main()
