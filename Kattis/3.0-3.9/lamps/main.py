h, p = map(int, input().split())
p/=100000
t = 0
d = 0
while 60*t*p+(t+999)//1000*5 <= 11*t*p+60:
    t += h
    d += 1
print(d)
