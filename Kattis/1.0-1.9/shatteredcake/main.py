w = int(input())
n = int(input())
t = 0
for _ in range(n):
    x, y = map(int, input().split())
    t += x*y
print(t // w)
