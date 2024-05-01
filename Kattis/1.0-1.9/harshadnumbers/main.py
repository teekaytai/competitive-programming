i=int(input())
while i%sum(map(int,str(i))):i+=1
print(i)
