import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n, k = map(int, input().split())
    print('abcdefghijklmnopqrstuvwxyz'[:k] * n)
