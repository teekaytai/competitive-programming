n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort()
a.append(9999999999)
t = 0
i = 0
while t <= 5*m: t += a[i]; i+=1
print(i-1)
