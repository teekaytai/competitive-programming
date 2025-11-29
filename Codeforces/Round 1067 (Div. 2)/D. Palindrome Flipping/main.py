import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def f(s):
    ans = []
    n = len(s)
    k = -1
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            k = i
            break
    if k == -1:
        k = 0
        s[1] = 1 - s[1]
        s[2] = 1 - s[2]
        s[3] = 1 - s[3]
        ans.append((1, 3))
    b = s[k]
    for i in range(k + 2, n):
        if s[i] == b:
            continue
        ans.append((k, i - 1))
        b = 1 - b
    for i in range(k - 1, -1, -1):
        if s[i] == b:
            continue
        ans.append((i + 1, n - 1))
        b = 1 - b
    if b == 1:
        ans.append((0, n - 1))
    assert len(ans) <= n
    return ans


def main():
    n = int(input())
    s = list(map(int, input()))
    t = list(map(int, input()))
    a = f(s) + f(t)[::-1]
    print(len(a))
    for u, v in a:
        print(u + 1, v + 1)

tcs = int(input())
for tc in range(tcs):
    main()
