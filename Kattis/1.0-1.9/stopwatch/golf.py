n,*a=map(int,open(0))
print([sum(a)-2*sum(a[::2]),'still running'][n%2])