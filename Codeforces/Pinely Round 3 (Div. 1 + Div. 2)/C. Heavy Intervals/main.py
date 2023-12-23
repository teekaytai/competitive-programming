tcs = int(input())
for tc in range(tcs):
    n = int(input())
    l = [int(x) for x in input().split()]
    r = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    l.sort(reverse=True)
    r.sort()
    idx = 0
    while r[idx] <= l[0]:
        idx += 1
    lo = idx
    hi = lo + 1
    st = []
    c.sort(reverse=True)
    a = []
    for i in range(n):
        while lo > 0 and r[lo - 1] > l[i]:
            st.append(r[lo])
            lo -= 1
        if lo >= 0 and r[lo] > l[i]:
            a.append(r[lo] - l[i])
            lo -= 1
        elif st:
            a.append(st.pop() - l[i])
        else:
            a.append(r[hi] - l[i])
            hi += 1
    a.sort()
    print(sum(x*y for x,y in zip(a,c)))
