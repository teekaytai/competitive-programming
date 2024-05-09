a,b=input().split(' ')
print(2**(1+int(a))-int('1'+b.replace('L','0').replace('R','1'),2))
