n = int(input())
ysmx = nsmx = ys = ns = 0
ylmx = nlmx = l = 0
for _ in range(n):
    if input()[0] == 'Y':
        ys += 1
        ysmx = max(ysmx, ys)
        ns = 0
        l += 1
        ylmx = max(ylmx, l)
    else:
        ns += 1
        nsmx = max(nsmx, ns)
        ys = 0
        l -= 1
        nlmx = max(nlmx, -l)
cmp = lambda a,b: (a>b)-(a<b)
print('Agree' if cmp(ysmx,nsmx)==cmp(ylmx,nlmx) else 'Disagree')
