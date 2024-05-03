n = int(input())
m = 12*(n-2018)-4
print(['no','yes'][m%26>(m+13)%26])
