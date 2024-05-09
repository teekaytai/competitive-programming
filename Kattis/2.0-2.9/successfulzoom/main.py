n = int(input())
*a, = map(int, input().split())
for i in range(1, n//2+1):
    b = a[i-1::i]
    if all(y>x for x,y in zip(b, b[1:])): print(i); break
else:
    print('ABORT!')
