n = int(input())
*a, = map(int, input().split())
print(min(a)*(n-2)+sum(a))
