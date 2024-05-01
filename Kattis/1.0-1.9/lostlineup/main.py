r = [1]*int(input())
for i, x in enumerate(map(int, input().split()), start=2):
    r[x+1] = i
print(*r)
