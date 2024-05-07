n, m = map(int, input().split())
a = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))
j = 0
for i in range(m):
    if b[i] >= a[j]:
        j += 1
        if j >= n: break
print(j)
