n = int(input())
a = sorted(map(int, input().split()))
b = [x/y for x,y in zip(a, range(1, n+1))]
print(min(b) if max(b)<=1 else 'impossible')
