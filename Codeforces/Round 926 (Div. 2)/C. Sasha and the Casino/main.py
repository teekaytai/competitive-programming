import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        k, x, a = map(int, input().split())
        s = 0
        for i in range(x):
            s += s // (k-1) + 1
        # print(k, x, a, s)
        print('YES' if a - s > 0 and (a - s)*k > a else "NO")

main()
