n = int(input())
t, h = map(float, input().split())
s = 0
for _ in range(n-1):
    t2, h2 = map(float, input().split())
    s += (h+h2)/2*(t2-t)
    t=t2;h=h2
print(s / 1000)
