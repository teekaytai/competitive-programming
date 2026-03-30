n = int(input()) + 1
c = [1] * n
for i in range(2, n):
    for j in range(i, n, i):
        c[j] += 1
print('\n'.join(map(str, c[1:])))
