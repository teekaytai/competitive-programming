l, r = map(int, input().split())
print('Not a moose' if not l+r else ['Odd','Even'][l==r] + ' ' + str(max(l, r) * 2))
