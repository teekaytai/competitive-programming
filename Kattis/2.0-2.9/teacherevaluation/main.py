n, p = map(int, input().split())
s = sum(map(int, input().split()))
if p == 100: print('impossible')
else:
    print((p*n-s-p+99)//(100-p))
