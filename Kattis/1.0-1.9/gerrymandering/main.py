n, m = map(int, input().split())
a = [0] * m
b = [0] * m
for _ in range(n):
    i, x, y = map(int, input().split())
    a[i-1] += x
    b[i-1] += y
t1 = t2 = 0
for x, y in zip(a, b):
    m = max(x, y) - (x+y)//2 - 1
    if x > y:
        print('A', m, y)
        t1 += m; t2 += y
    else:
        print('B', x, m)
        t1 += x; t2 += m
print(abs(t1-t2)/(sum(a)+sum(b)))
