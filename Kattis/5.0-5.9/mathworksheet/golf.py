w=0
while n:=int(input()):w and print();w=max(map(len,a:=[str(eval(input()))for _ in[0]*n]));l=51//-~w;[print(*(f'{x:>{w}}'for x in a[i:i+l]))for i in range(0,n,l)]