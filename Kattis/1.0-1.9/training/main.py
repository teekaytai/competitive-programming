n, s = map(int, input().split())
for _ in range(n):
    l, r = map(int, input().split())
    s += l <= s <= r
print(s)
