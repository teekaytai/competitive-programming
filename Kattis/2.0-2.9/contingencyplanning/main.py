n = int(input())
t = 0
c = 1
f = 1
for i in range(1, n+1):
    c = c * (n - i + 1) // i
    f *= i
    t += c * f
    if t > 1000000000: print('JUST RUN!!'); break
else:
    print(t)
