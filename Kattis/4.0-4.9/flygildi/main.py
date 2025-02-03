from math import dist
import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    home = 0, 0
    ps = [tuple(map(int, input().split())) for _ in range(n)]
    if n > 8 or all(p[0] == 0 for p in ps):
        ps.append(home)
        print(2 * (max(p[1] for p in ps) - min(p[1] for p in ps)))
    else:
        ps.append(home)
        ds = [[dist(ps[i], ps[j]) for j in range(n + 1)] for i in range(n + 1)]
        def dfs(best, m, d, p):
            if d >= best: return best
            if not m: return min(best, d + ds[p][-1])
            c = m
            while c:
                b = c & -c
                p2 = b.bit_length() - 1
                best = dfs(best, m - b, d + ds[p][p2], p2)
                c -= b
            return best
        print(dfs(100000000, (1 << n) - 1, 0, -1))
main()
