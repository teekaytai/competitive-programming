import sys
input = lambda: sys.stdin.readline().strip()
while True:
    n, m = map(int, input().split())
    if n+m==0: break
    print(len({int(input()) for _ in range(n)}&{int(input()) for _ in range(n)}))
