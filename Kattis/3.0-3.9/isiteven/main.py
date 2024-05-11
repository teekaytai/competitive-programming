n, k = map(int, input().split())
for _ in range(n):
    x = int(input())
    while x%2==0: x//=2; k -= 1
print(int(k<=0))
