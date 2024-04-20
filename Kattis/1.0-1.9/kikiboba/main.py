s=input()
k=s.count('k')
b=s.count('b')
print(['none','boba','kiki','boki'][(k+b>0)*((k==b)*3+(k>b)*2+(k<b))])
