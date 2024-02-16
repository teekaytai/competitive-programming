import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        n = int(input())
        *a, = map(int, input().split())
        print(max(a) - min(a))

main()
