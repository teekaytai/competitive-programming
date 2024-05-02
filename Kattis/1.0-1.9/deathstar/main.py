from functools import reduce
print(*[reduce(int.__or__, map(int, input().split())) for _ in range(int(input()))])
