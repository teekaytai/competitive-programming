MOD = 1000000007
n, T = map(int, input().split())
a, b, c, t = map(int, input().split())
s = [0] * (c + 1)
for i in range(1, n+1):
    s[t] = i
    t = (a*t + b) % c + 1
    if s[t]: break
L = i - s[t] + 1
x = 0
y = 0
z = 0
for j in range(1, c+1):
    if z + j > T: break
    if not s[j]: continue
    m = 1 if s[j] < s[t] else min((T - z) // j, 1 + (n - s[j]) // L)
    x += m
    y = (y + z * m + j * m*(m+1)//2) % MOD
    z += m * j
print(x, y)
