a, b, c = map(int, input().split())
t = 0
for i in range(a):
    x = int(input())
    if x > b + c:
        t += 1
        b, c = x, b
print(t)
