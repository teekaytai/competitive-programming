import math
h, w = map(int, input().split())
grid = []
for _ in range(h):
    grid.append(list(input()))

L = 2.5 * math.pi

dp1 = [5. * x for x in range(2 * w + 1)]
dp2 = [0.] * (w + 1)

for i in range(2 * h):
    if i % 2 == 0:
        dp2[0] = dp1[0] + 5
        for j in range(w):
            if grid[i // 2][j] == 'X':
                dp2[j + 1] = dp1[2 * j + 2] + 5
            else:
                dp2[j + 1] = min(dp1[2 * j + 1] + L, dp1[2 * j + 2] + 5)
    else:
        dp1[0] = dp2[0] + 5
        for j in range(2 * w):
            if j % 2 == 0:
                dp1[j + 1] = dp1[j] + 5
                if grid[i // 2][j // 2] == 'O':
                    dp1[j + 1] = min(dp1[j + 1], dp2[j // 2] + L)
            else:
                dp1[j + 1] = min(dp1[j], dp2[j // 2 + 1]) + 5

print(dp1[-1])
