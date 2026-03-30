n = int(input())
a = [[4, n-4], [9, n-9]][n % 2]
print(len(a))
print(*a)
