a, b, c, n = map(int, input().split())
x = []
for i in range(n//a+1):
    n2 = n - a*i
    for j in range(n2//b+1):
        n3 = n2 - b*j
        if n3 % c == 0: x.append(f'{i} {j} {n3//c}')
print(*x or ['impossible'], sep='\n')
