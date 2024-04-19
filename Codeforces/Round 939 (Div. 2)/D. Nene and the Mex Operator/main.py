import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    mxs = [[0]*n for _ in range(n)]
    ps = [[-1]*n for _ in range(n)]
    for i in range(n):
        if a[i] >= 1:
            mxs[i][i] = a[i]
            ps[i][i] = i
        else:
            mxs[i][i] = 1
    for l in range(1, n):
        for i in range(n-l):
            j = i + l
            mxs[i][j] = (l+1)**2
            s = a[i] + mxs[i+1][j]
            if s > mxs[i][j]:
                mxs[i][j] = s
                ps[i][j] = i
            s = mxs[i][j-1] + a[j]
            if s > mxs[i][j]:
                mxs[i][j] = s
                ps[i][j] = j
            for m in range(i+1, j):
                s = mxs[i][m-1] + a[m] + mxs[m+1][j]
                if s > mxs[i][j]:
                    mxs[i][j] = s
                    ps[i][j] = m
    o = []
    def f(i, j, v):
        if v == 1:
            o.append((i, j))
            return
        for k in range(1, v):
            f(i+k-1, j-1, v-k)
            o.extend([(l, l) for l in range(i+k, j)])
        o.append((i, j))

    def dfs(i, j):
        if ps[i][j] == -1:
            for k in range(i, j+1):
                if a[k] != 0: o.append((k, k))
            f(i, j, j-i+1)
        else:
            if ps[i][j] > i: dfs(i, ps[i][j] - 1)
            if ps[i][j] < j: dfs(ps[i][j] + 1, j)
    dfs(0, n-1)
    print(mxs[0][n-1], len(o))
    for i, j in o: print(i+1, j+1)
main()
