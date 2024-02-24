import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        n = int(input())
        *a, = map(int, input().split())
        if 1 not in a: print(0);continue
        while a and a[-1]==0:a.pop()
        l = a.index(1)
        print(a[l:].count(0))

main()
