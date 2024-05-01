_,*a=open(0)
for s in a:
    x=round(len(s)**.5)
    print(''.join(s[x-i-1::x]for i in range(x)),end='')
