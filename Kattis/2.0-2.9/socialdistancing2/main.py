n, m = map(int, input().split())
*a, = map(int, input().split())
a.append(a[0]+n)
print(sum((y-x-2)//2 for x, y in zip(a, a[1:])))
