n, l, r = map(int, input().split())
rule = f'{n:08b}'
a = ['0']*(r+1) + [*input()] + ['0']*(r+1)
L = (l+2*r+2)
na = ['0'] * L
x = '0'
for _ in range(r):
    x = rule[-1] if x == '0' else rule[0]
    na[0] = na[-1] = x
    for i in range(1, L-1):
        na[i] = rule[7-int(''.join(a[i-1:i+2]), 2)]
    a,na = na,a
    print(''.join(a[r+1:-r-1]))
