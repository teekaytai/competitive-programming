n=int(input())
a = sorted(map(int, input().split()))
print(sum(x//2 for x in a[:n//2+1]) + sum(a[n//2+1:]))
