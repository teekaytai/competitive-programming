import sys

input = lambda: sys.stdin.readline().strip()

ans = []
while True:
    n, d, m = map(int, input().split())
    if n==0: break
    N = n+d+d
    d2 = d*d
    moles = [[[0]*N for _ in range(N)] for _ in range(10)]
    for _ in range(m):
        x, y, t = map(int, input().split())
        moles[t-1][x][y] = 1
    dp1 = [[0]*N for _ in range(N)]
    for t, mt in enumerate(moles):
        dp2 = [[0]*N for _ in range(N)]
        for x in range(-d, n+d):
            for y in range(-d, n+d):
                v = dp1[x][y] + mt[x][y]
                dp2[x][y] = max(dp2[x][y], v)
                for vx in range(-d, d+1):
                    for vy in range(-d, d+1):
                        if vx==vy==0: continue
                        dx = vx
                        dy = vy
                        v2 = v
                        while dx**2+dy**2 <= d2 and -d<=(x2:=x+dx)<n+d and -d<=(y2:=y+dy)<n+d:
                            v2 += mt[x2][y2]
                            dp2[x2][y2] = max(dp2[x2][y2], v2)
                            dx += vx
                            dy += vy
        dp1 = dp2

    ans.append(max(v for row in dp1 for v in row))

print(*ans, sep='\n')
