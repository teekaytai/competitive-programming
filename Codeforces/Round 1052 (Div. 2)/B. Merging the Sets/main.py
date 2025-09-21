import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    cs = [0] * (m + 1)
    ss = []
    for _ in range(n):
        k, *a = map(int, input().split())
        ss.append(a)
        for v in a:
            cs[v] += 1
    if any(cs[i] == 0 for i in range(1, m + 1)):
        print('NO')
        return
    can = 0
    for a in ss:
        if all(cs[v] > 1 for v in a):
            can += 1
        if can == 2:
            print('YES')
            return
    print('NO')

tcs = int(input())
for tc in range(tcs):
    main()
