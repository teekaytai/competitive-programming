n, t = map(int, input().split())
*a, = map(int, input().split())
if t == 1:
    print(7)
elif t == 2:
    print('Bigger'if a[0]>a[1] else 'Equal'if a[0]==a[1] else 'Smaller')
elif t == 3:
    _,m,_=sorted(a[:3])
    print(m)
elif t == 4:
    print(sum(a))
elif t == 5:
    print(sum(x for x in a if x%2==0))
elif t == 6:
    print(''.join(chr(ord('a')+x%26) for x in a))
elif t == 7:
    i = 0
    while 0 <= i < n-1:
        if a[i] == i:
            print('Cyclic')
            break
        a[i],i=i,a[i]
    else:
        print('Done'if i==n-1 else 'Out')
