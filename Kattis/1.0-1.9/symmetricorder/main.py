i=0
while n:=int(input()):
    print('SET', i:=i+1)
    a = [input()for _ in range(n)]
    print(*a[::2], *a[len(a)%-2-1::-2],sep='\n')
