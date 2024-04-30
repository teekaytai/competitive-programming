_,p,*a=open(0)
print(max((i-j)*all(p[j:i]in s for s in a)for i in range(1,len(p))for j in range(i)))