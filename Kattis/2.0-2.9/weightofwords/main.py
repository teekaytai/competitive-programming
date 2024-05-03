l,w = map(int, input().split())
q,r = divmod(w,l)
if q < 1 or q > 26 or q==26 and r: print('impossible')
else: print(chr(96+q)*(l-r)+chr(96+q+1)*r)
