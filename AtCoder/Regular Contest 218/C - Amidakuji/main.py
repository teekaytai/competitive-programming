import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    print(2, flush=True)
    print(n, *range(2, n), 1, flush=True)
    print(*range(2, n), 1, n, flush=True)
    q = [int(x) for x in input().split()]
    a = list(range(1, n + 1))
    assert q != [-1]
    m = n - 1
    ans = []
    rot = 0
    for i in range(n - 1):
        if q[i] == a[i]:
            continue
        j = a.index(q[i])
        if j != n - 1:
            ans += (j - rot) % m * [2]
            rot = j
            ans.append(1)
            a[j], a[-1] = a[-1], a[j]
        ans += (i - rot) % m * [2]
        rot = i
        ans.append(1)
        a[i], a[-1] = a[-1], a[i]
    ans += -rot % m * [2]
    rot = 0
    print(len(ans), ' '.join(map(str, ans)), flush=True)

main()
