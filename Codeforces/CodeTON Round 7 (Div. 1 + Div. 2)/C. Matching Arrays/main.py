t = int(input())
for I in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    ids = list(range(n))
    ids.sort(key=lambda i: a[i])
    b.sort()
    b = b[k:] + b[:k]
    f = all(b[i] >= a[ids[i]] for i in range(n - k)) and all(b[i] < a[ids[i]] for i in range(n - k, n))
    if f:
        print('YES')
        for idx, bx in zip(ids, b):
            a[idx] = bx
        print(*a)
    else:
        print('NO')
