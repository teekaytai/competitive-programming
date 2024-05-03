n = int(input())
a = sorted(map(int, input().split()))
print('im'*all(a[i]+a[i+1]<=a[i+2]for i in range(n-2))+'possible')
