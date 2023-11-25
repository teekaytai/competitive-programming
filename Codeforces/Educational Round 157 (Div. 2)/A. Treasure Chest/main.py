t = int(input())
for I in range(t):
    x, y, k = map(int, input().split())
    if y > x:
        print(y + max(y - (x + k), 0))
    else:
        print(x)

