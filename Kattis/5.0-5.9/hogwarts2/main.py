import sys

input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    g1 = [(*map(int, input().split()),) for _ in range(n)]
    g2 = [(*map(int, input().split()),) for _ in range(n)]
    block = (0, 0, 0, 0)
    dp = [[False] * (n+1) for _ in range(n+1)]
    dp[1][1] = True
    s = [(1, 1)]
    while s:
        v1, v2 = s.pop()
        for u1, u2 in zip(g1[v1-1], g2[v2-1] if v2 else block):
            if u1 == n != u2:
                print('No')
                return
            if u1 == 0 or dp[u1][u2]: continue
            dp[u1][u2] = True
            s.append((u1, u2))
    print('Yes' if dp[n][n] else 'Impossible')

main()
