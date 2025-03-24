for _ in range(int(input())):
    n = int(input())
    *a, = 0, *map(int, input().split())
    for i in range(1, n + 1):
        if not a[i]: continue
        c = a[i]
        l = 1
        while c != i:
            a[c], c = 0, a[c]
            l += 1
        if l & (l - 1): print('Some starve.'); break
        a[i] = 0
    else:
        print('All can eat.')
