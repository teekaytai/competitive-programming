from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

N = 200002
ps = [-1] * N
for i in range(2, N):
    if ps[i] != -1: continue
    for j in range(i, N, i):
        ps[j] = i

def main():
    n = int(input())
    C = Counter()
    m = n
    while ps[m] != -1:
        C[ps[m]] += 1
        m //= ps[m]

    ans = []

    for t in range(n):
        m = abs(n - 2 * t)
        if m == 0: continue
        c = C.copy()
        while ps[m] != -1:
            c[ps[m]] += 1
            m //= ps[m]
        if c:
            ks, vs = zip(*c.items())
        else:
            ks, vs = (), ()
        s = n * (n - 2 * t)

        st = [1]
        st2 = [0]
        while st:
            p = st.pop()
            i = st2.pop()
            if i == len(ks):
                q = s // p
                if p > abs(q): continue
                a = p + n - t
                b = q + n - t
                if a & t == b & t == a & b == 0 and t | a > 0 and t | b > 0:
                    ans.append((t | a, t | b))
                if p != -q:
                    a = -p + n - t
                    b = -q + n - t
                    if a & t == b & t == a & b == 0 and t | a > 0 and t | b > 0:
                        ans.append((t | a, t | b))
                continue
            for j in range(vs[i] + 1):
                st.append(p)
                st2.append(i + 1)
                p *= ks[i]

    print(len(ans))
    for x, y in ans:
        print(x, y)

main()
