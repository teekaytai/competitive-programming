import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, q = map(int, input().split())
    *p, = map(int, input().split())
    s = [1 if c == 'R' else -1 for c in input()]
    g = 0
    m = 0
    ids = [0] * n
    rs = []
    lo = 0
    for i, x in enumerate(p):
        ids[i] = g
        x -= 1
        m = max(m, x)
        if m == i:
            rs.append((lo, i))
            g += 1
            m = 0
            lo = i + 1
    a = []
    for l, r in rs:
        a.append(sum(s[i] != 1 and s[i+1] != -1 for i in range(l, r)))
    C = sum(v != 0 for v in a)
    # printerr(C, a)
    for _ in range(q):
        k = int(input())
        k -= 1
        l, r = rs[ids[k]]
        x = s[k]
        if x == 1 and k != r and s[k+1] != -1:
            a[ids[k]] += 1
            if a[ids[k]] == 1: C += 1
        if x == -1 and k != l and s[k-1] != 1:
            a[ids[k]] += 1
            if a[ids[k]] == 1: C += 1
        x = -x
        s[k] = x
        if x == 1 and k != r and s[k+1] != -1:
            a[ids[k]] -= 1
            if a[ids[k]] == 0: C -= 1
        if x == -1 and k != l and s[k-1] != 1:
            a[ids[k]] -= 1
            if a[ids[k]] == 0: C -= 1
        # printerr(C, a)
        print(['NO', 'YES'][C==0])



tcs = int(input())
for tc in range(tcs):
    main()
