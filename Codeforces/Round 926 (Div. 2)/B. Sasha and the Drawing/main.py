import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        n, k = map(int, input().split())
        print((k+1) // 2 + (k == n*4-2))

main()
