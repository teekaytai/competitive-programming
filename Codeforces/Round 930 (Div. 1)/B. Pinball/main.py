from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    tcs = int(input())
    for tc in range(tcs):
        n = int(input())
        s = input()
        ls = []
        lids = []
        rs = []
        rids = []
        for i, x in enumerate(s):
            lids.append(len(ls))
            if x == '>':
                ls.append(i)
        for i in range(n-1, -1, -1):
            rids.append(len(rs))
            if s[i] == '<':
                rs.append(i)
        rids.reverse()
        if not ls:
            print(*range(1, n+1))
            continue
        if not rs:
            print(*range(n, 0, -1))
            continue
        *lps, = accumulate(ls, initial=0)
        *rps, = accumulate(rs, initial=0)
        ans = []
        for i, x in enumerate(s):
            if (x == '>' and rids[i] <= lids[i]) or (x == '<' and rids[i] < lids[i]):
                ans.append(2 * (rps[rids[i]] - lps[lids[i]] + lps[lids[i] - rids[i] - (x=='<')] + i*(x=='<')) + n - i)
            else:
                ans.append(2 * (rps[rids[i]] - rps[rids[i] - lids[i] - (x=='>')] - lps[lids[i]] - i*(x=='>')) + i + 1)
        print(*ans)

main()
