t = int(input())
for _ in range(t):
    i, n = map(int, input().split())
    a = b = 1
    for bit in bin(n)[3:]:
        if bit == '0':
            b = a + b
        else:
            a = a + b
    print(i, f'{a}/{b}')
