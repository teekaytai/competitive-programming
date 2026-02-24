import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    st = []
    t = 0
    for i, x in enumerate(a):
        while st and a[st[-1]] + 1 != x:
            st.pop()
        if not st:
            t += (i + 1) * (n - i)
        else:
            t += (i - st[-1]) * (n - i)
        st.append(i)
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
