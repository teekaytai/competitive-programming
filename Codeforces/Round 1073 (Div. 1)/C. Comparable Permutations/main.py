import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(i, j):
    print('?', i+1, j+1, flush=True)
    return int(input())
    # return int(sekrut[i] < sekrut[j])

def a(x):
    if x==-1:
        print('! -1', flush=True)
        # s_rev = sekrut[::-1]
        # for p in permutations(range(1, len(sekrut) + 1)):
        #     if p > sekrut and p[::-1] > s_rev:
        #         assert False, f'\n{sekrut}\nExpected: {p}\nGot: -1'
    else:
        print('!', *x, flush=True)
        # s_rev = sekrut[::-1]
        # q = tuple(sekrut[i-1] for i in x)
        # for p in permutations(range(1, len(sekrut) + 1)):
        #     if p > sekrut and p[::-1] > s_rev:
        #         assert q == p, f'\n{sekrut}\nExpected: {p}\nGot: {q}'
        #         break
        # else:
        #     assert False, f'\n{sekrut}\nExpected: -1\nGot: {q}'


def main():
    n = int(input())
    # n = len(sekrut)
    for i in range(n - 2, -1, -1):
        if q(i, i+1) == 0:
            break
    else:
        a(-1)
        return
    ans = list(range(1, n+1))
    p = i
    for i in range(p-1, -1, -1):
        if q(i, i+1) == 1:
            break
    else:
        a(-1)
        return
    s = i
    v = s + 1
    for i in range(p+1, n):
        if q(s, i) == 1:
            v = i
            break
    for i in range(p, s, -1):
        if q(s, i) == 1:
            if q(v, i) == 1:
                ans[s], ans[v] = ans[v], ans[s]
            else:
                ans[s], ans[i] = ans[i], ans[s]
            break
    l = s + 1
    m = p
    r = p + 1
    ans2 = ans[:]
    i = l
    while l <= m and r < n:
        if q(m, r) == 1:
            ans2[i] = ans[m]
            m -= 1
        else:
            ans2[i] = ans[r]
            r += 1
        i += 1
    for m in range(m, l - 1, -1):
        ans2[i] = ans[m]
        i += 1
    for r in range(r, n):
        ans2[i] = ans[r]
        i += 1
    a(ans2)

tcs = int(input())
for tc in range(tcs):
    main()

# print=lambda *args, **kwargs: None
# from itertools import permutations
# for sekrut in permutations(range(1, 8)):
#     main()
