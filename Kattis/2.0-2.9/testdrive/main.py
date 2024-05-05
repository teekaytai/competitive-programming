a,b,c = map(int, input().split())
if a<b>c or a>b<c: print('turned')
else: print(['braked','cruised','accelerated'][(abs(c-b)>=(abs(b-a)))+(abs(c-b)>(abs(b-a)))])
