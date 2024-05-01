*a, = map(int, input().split())
x=int(input())
print(chr(65+next((i for i in range(5) if a[i] <= x), 5)))
