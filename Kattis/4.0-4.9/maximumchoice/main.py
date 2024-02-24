n, b = map(int, input().split())
i = 0
while n > b:
    n = n // (b+1)
    i += 1
print(i + 1)
