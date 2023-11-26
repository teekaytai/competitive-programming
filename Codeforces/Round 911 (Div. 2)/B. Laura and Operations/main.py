tcs = int(input())
for tc in range(tcs):
    a, b, c = map(int, input().split())
    print(1 - (b - c) % 2, 1 - (a - c) % 2, 1 - (a - b) % 2)
