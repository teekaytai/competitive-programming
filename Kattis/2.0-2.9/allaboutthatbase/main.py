A = []
for _ in range(int(input())):
    a = input().split()
    b = [*a]
    b[-2] = '=='
    ans = []
    for i, d in enumerate('123456789abcdefghijklmnopqrstuvwxyz0', start=1):
        try:
            if i == 1:
                if any(c != '1' for num in (a[0], a[2], a[4]) for c in num):
                    raise ValueError
                b[0] = str(len(a[0]))
                b[2] = str(len(a[2]))
                b[4] = str(len(a[4]))
            else:
                b[0] = str(int(a[0], i))
                b[2] = str(int(a[2], i))
                b[4] = str(int(a[4], i))
            if eval(''.join(b)): ans.append(d)
        except: pass
    A.append(''.join(ans or ['invalid']))
    # print(''.join(ans or ['invalid']))
for x in A:
    print(x)
