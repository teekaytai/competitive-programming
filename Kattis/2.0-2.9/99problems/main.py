n = int(input())
if n < 99: print(99)
else:
    d = 99-n%100
    print(min(n+d, n-100+d, key=lambda x:abs(n-x)))
