def f(n):
    return all(n%i for i in range(2, int(n**.5)+1))
*a, _ = map(int, open(0))
for x in a:
    y = 2*x+1
    while not f(y): y += 1
    print(*[y] + [f'({x} is not prime)']*(1-f(x)))
