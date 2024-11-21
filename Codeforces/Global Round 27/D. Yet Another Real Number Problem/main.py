import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007

def main():
    n = int(input())
    *a, = map(int, input().split())
    b = []
    c = []
    for x in a:
        q = 1
        while x % 2 == 0:
            x //= 2
            q *= 2
        b.append(x)
        c.append(q)
    st = []
    curr = 0
    ans = []
    for x, p, q in zip(a, b, c):
        chonk = False
        while st and (st[-1][0] <= x or chonk):
            p2, q2 = st.pop()
            curr = (curr - p2 * (q2 - 1)) % MOD
            q = q * q2 % MOD
            x *= q2
            if x > MOD:
                chonk = True
                x %= MOD
        st.append((p, q))
        curr = (curr + p * q) % MOD
        ans.append(curr)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
