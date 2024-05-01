t = int(input())
for _ in range(t):
    i, n = input().split()
    try:
        octal = int(n, 8)
    except:
        octal = 0
    decimal = int(n, 10)
    hexa = int(n, 16)
    print(i, octal, decimal, hexa)
