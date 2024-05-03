n=int(input())
if n % 2: print((n+1)//2, n//2)
elif n % 4 == 0: x = n//2; print(x//2+1, x//2-1)
else: print('impossible')
