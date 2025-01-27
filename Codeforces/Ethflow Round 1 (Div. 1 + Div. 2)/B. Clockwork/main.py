import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    # t = 1
    # for i in range(1, n):
    #     if a[i] <= t: return False
    #     t += 1

    # b = [x>=2*n for x in a]
    # ds = []
    # t = 0
    for i, x in enumerate(a):
        if x <= max(2*i, (n - i - 1) * 2):
            return False
        # ds.append(d)
    # print(a[0]>=)
    return True

tcs = int(input())
for tc in range(tcs):
    print(['NO','YES'][main()])
