tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = input()
    p=a.count('+')
    m=n-p
    print(max(m,p)-min(m,p))
