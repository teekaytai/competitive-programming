from math import pi
n, s, a, x, b = open(0).read().split()
x = int(x)
r2 = (x/pi if s[0]=='C' else x/4) if a == 'A' else (x/2/pi)**2 if s[0] == 'C' else (x/8)**2
r2 /= pow(2, int(n) - s[1:].count('C') - 1)
print((pi*r2 if s[-1]=='C' else r2*4) if b == 'A' else r2**.5*2*pi if s[-1] == 'C' else r2**.5*8)
