t = int(input())
for _ in range(t):
    i, n = map(int, input().split())
    a = []
    while len(a) < n:
        a += list(int(x) for x in input().split())

    st = []
    res = 0
    smallest_del = float('inf')
    for x in a:
        while st and st[-1] > x:
            res += 1
            smallest_del = min(smallest_del, st.pop())
        st.append(x)
    while st and st[-1] > smallest_del:
        res += 1
        st.pop()
    print(i, res)
