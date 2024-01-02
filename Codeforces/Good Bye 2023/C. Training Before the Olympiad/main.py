tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = [*map(int,input().split())]
    t = 0
    o = 0
    ans = []
    for i, v in enumerate(a, start=1):
        t += v
        o += v%2
        q,r = divmod(o,3)
        ans.append(t - q - (r==1 and i>1))
    print(*ans)
