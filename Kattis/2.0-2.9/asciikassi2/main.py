n=int(input())
print(' '*(n+1)+'x')
for i in range(1, n+1):
    print(' '*(n+1-i)+'/'+' '*(2*i-1)+'\\')
print('x'+' '*(2*n+1)+'x')
for i in range(n, 0, -1):
    print(' '*(n+1-i)+'\\'+' '*(2*i-1)+'/')
print(' '*(n+1)+'x')
