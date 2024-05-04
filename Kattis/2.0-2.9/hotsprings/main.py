n = int(input())
a = sorted(map(int, input().split()))
i = n // 2
j = i - 1
b = []
while i < n:
    b.append(a[i])
    i += 1
    if j >= 0:
        b.append(a[j])
        j -= 1
print(*b)
