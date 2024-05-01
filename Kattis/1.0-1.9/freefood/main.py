a = [False] * 366
for _ in range(int(input())):
    l, r = map(int, input().split())
    a[l:r+1] = [True] * (r-l+1)
print(sum(a))
