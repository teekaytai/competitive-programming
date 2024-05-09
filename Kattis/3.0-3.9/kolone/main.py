n, m = map(int, input().split())
s = input()
t = input()
a = [''] * (4*(m+n)+2)
k = min(int(input()), n+m-1)
a[2*m-1:2*(m+n)-1:2] = s[::-1]
a[2*(m+n)-2-2*k:2*(m+n+m)-2-2*k:2] = t
print(''.join(a))
