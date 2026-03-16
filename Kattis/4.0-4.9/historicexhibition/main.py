n, m = map(int, input().split())
a = [tuple(sorted(map(int, input().split()))) for _ in range(n)]
J = sorted(range(n), key=a.__getitem__)
b = [int(x) for x in input().split()]
I = sorted(range(m), key=b.__getitem__)
ans = [0] * m
j = 0
for i in I:
    x = b[i]
    while j < n:
        if x in a[J[j]]:
            ans[i] = J[j] + 1
            break
        j += 1
    else:
        print('impossible')
        break
    j += 1
else:
    for j in ans:
        print(j)
