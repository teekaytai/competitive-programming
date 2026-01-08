import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    print('? L', flush=True)
    k1, *q1 = [int(x) for x in input().split()]
    print('? LR', flush=True)
    k2, *q2 = [int(x) for x in input().split()]
    print('? R', flush=True)
    k3, *q3 = [int(x) for x in input().split()]
    bs = [False] * n
    qi = 0
    for i, x in enumerate(a):
        if qi < k2 and q2[qi] == x:
            bs[i] = True
            qi += 1
    qi = 0
    ans = [-1] * n
    for i, x in enumerate(a):
        if bs[i]:
            ans[i] = x - q1[qi]
            qi += 1
        elif ans[i - 1] == -1 or ans[i - 1] == 1 or q1[qi - 1] == x - 2:
            ans[i] = 2
        else:
            assert ans[i - 1] == 0 and q1[qi - 1] == x - 1
    qi = 0
    for i, x in enumerate(a):
        if ans[i] != -1:
            continue
        if i < n - 1 and a[i + 1] == x + 1 and ans[i + 1] == 0:
            print('! -1', flush=True)
            return
        y = a[i - 1]
        while q3[qi] != y:
            qi += 1
        qi += 1
        ans[i] = q3[qi] - x
    print('!', *ans, flush=True)

tcs = int(input())
for tc in range(tcs):
    main()
