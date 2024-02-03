import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    x, n = map(int, input().split())
    for i in range(n, int(x ** .5) + 1):
        if x % i == 0:
            print(x // i)
            break
    else:
        for i in range(min(int(x ** .5), x // n), 0, -1):
            if x % i == 0:
                print(i)
                break
