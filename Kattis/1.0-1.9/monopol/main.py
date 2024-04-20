input()
s = set(map(int, input().split()))
print(sum(i+j in s for i in range(1, 7) for j in range(1, 7))/ 36)
