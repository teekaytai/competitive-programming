import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a += a
    ls = [-1] * (2 * n)
    rs = [-1] * (2 * n)
    st = []
    for i, x in enumerate(a):
        while st and a[st[-1]] <= x:
            st.pop()
        if st:
            ls[i] = st[-1]
        st.append(i)
    for i in range(n):
        if ls[i] == -1 and ls[i + n] != -1:
            ls[i] = ls[i + n]
    st = []
    for i in range(2 * n - 1, -1, -1):
        x = a[i]
        while st and a[st[-1]] < x:
            st.pop()
        if st:
            rs[i] = st[-1]
        st.append(i)
    for i in range(n):
        if rs[i] >= n:
            rs[i] -= n
    ans = [0] * (n + 1)
    for i in range(n):
        l = ls[i]
        r = rs[i]
        x = a[i]
        if l == -1:
            l = r
            lt = (i - l if i >= l else i + n - l) * x
            rt = (r - i if r >= i else r + n - i) * x
        else:
            lt = (i - l if i >= l else i + n - l) * x * 2
            rt = (r - i if r >= i else r + n - i) * x * 2
        ans[l + 1] += rt
        ans[i + 1] -= rt
        if l > i:
            ans[0] += rt
        ans[i + 1] += lt
        ans[r + 1] -= lt
        if r < i:
            ans[0] += lt
    ans.pop()
    for i in range(n - 1):
        ans[i + 1] += ans[i]
    for i in range(n):
        ans[i] //= 2
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
