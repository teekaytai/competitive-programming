t = int(input())
for I in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    curr = a[0]
    total = 0
    for num in a:
        if num < curr:
            total += curr - num
        curr = num
    print(total + curr - 1)
