n, b, h, w = map(int, input().split())
m = 10000000
for _ in range(h):
    p = int(input())
    if max(map(int, input().split())) >= n: m = min(m, p)
if m*n <= b:
    print(m*n)
else:
    print('stay home')
