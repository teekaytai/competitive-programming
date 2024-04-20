n=int(input())
*a, = map(int, input().split())
print(sum(x for x in a if x>=0)/(n-a.count(-1)))
