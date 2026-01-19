n, m = map(int, input().split())
print(' _'*m)
if m % 2 == 1:
    for _ in range(n - 1): print('|'+'_ '*(m//2)+' '+' _'*(m//2)+'|')
    print('|_'+' _'*(m - 1)+'|')
elif n == 1:
    print('|_'+' _'*(m - 1)+'|')
else:
    for i in range(n - 1):
        if i == (n - 1) // 2: print('|'+' '*(2*m-1)+'|')
        else: print('|'+' |'*m)
    print('|'+'_|'*m)
