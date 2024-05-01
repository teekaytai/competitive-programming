n=int(input())
print(f'{n}:')
for i in range(2,(n+1)//2+1):
    if (n-i)%(2*i-1)==0 or n%(2*i-1)==0:print(f'{i},{i-1}')
    if n%i==0:print(f'{i},{i}')
