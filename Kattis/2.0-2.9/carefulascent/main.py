x, y = map(int, input().split())
n = int(input())
for _ in range(n):
    a, b, c = map(float, input().split())
    y -= (b-a) * (1-c)
print(x/y)
