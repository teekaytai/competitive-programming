n = int(input()) + 1
c = [1] * n
print(1)
for i in range(2, n):
    for j in range(i, n, i):
        c[j] += 1
    print(c[i])
