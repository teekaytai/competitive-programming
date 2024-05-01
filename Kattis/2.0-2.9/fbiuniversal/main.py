t = int(input())
D = {'B':'8','G':'C','I':'1','O':'0','Q':'0','S':'5','U':'V','Y':'V','Z':'2'}
B = '0123456789ACDEFHJKLMNPRTVWX'
c = [2,4,5,7,8,10,11,13]
for _ in range(t):
    i, x = input().split()
    *a, b = x
    n = sum(c * B.index(D.get(d, d)) for c, d in zip(c, a)) % 27
    if n == B.index(D.get(b, b)):
        t = 0
        for d in a:
            t = t * 27 + B.index(D.get(d, d))
        print(i, t)
    else:
        print(i, 'Invalid')
