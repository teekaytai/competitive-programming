*s,=map(int,input())
r=c=0
for x in s:
    r = 2*r+(x>1)
    c = 2*c+(x%2)
print(len(s),c,r)
