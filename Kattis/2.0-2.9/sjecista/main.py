n = int(input())
print(n * sum(i*(n-i-2) for i in range(1, n-2)) // 4)
