import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    ans = []
    if n % 2 == 0:
        s = a[0] + a[-1]
        if all(a[i] + a[-i-1] == s for i in range(n // 2)):
            ans.append(s)
    s = a[-1]
    while a and a[-1] == s:
        a.pop()
    if len(a) % 2 == 0 and all(a[i] + a[-i-1] == s for i in range(len(a) // 2)):
        ans.append(s)
    print(*sorted(ans))

main()
