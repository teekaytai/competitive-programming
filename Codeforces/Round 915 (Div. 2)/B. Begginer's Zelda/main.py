tcs = int(input())
for tc in range(tcs):
    n = int(input())
    adj_count = [0] * n
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj_count[u-1] += 1
        adj_count[v-1] += 1
    print((adj_count.count(1)+1)//2)
