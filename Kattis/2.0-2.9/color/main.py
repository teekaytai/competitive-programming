s, c, k = map(int, input().split())
t = 0
p, *a = sorted(map(int, input().split()))
l = 1
for x in a:
    if l < c and x <= p + k:
        l += 1
    else:
        t += 1
        l = 1
        p = x
print(t + 1)
