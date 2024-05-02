a,b,c = map(int, input().split())
t=0
a+=b
while a >= c:
    q, r = divmod(a, c)
    t += q
    a = q + r
print(t)
