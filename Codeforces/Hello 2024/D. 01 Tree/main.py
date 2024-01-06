tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    prev = [*range(-1, n-1)]
    nxt = [*range(1,n),-1]
    b = sorted(range(n),key=lambda i:a[i],reverse=True)
    if a.count(0) != 1:
        print('NO')
        continue
    can = True
    for i in b[:-1]:
        v = a[i]
        if prev[i]>=0 and 0<=v-a[prev[i]]<=1 or nxt[i]>=0 and 0<=v-a[nxt[i]]<=1:
            if prev[i]>=0:nxt[prev[i]] = nxt[i]
            if nxt[i]>=0:prev[nxt[i]] = prev[i]
        else:
            can = False
            break
    print('YES' if can else 'NO')
