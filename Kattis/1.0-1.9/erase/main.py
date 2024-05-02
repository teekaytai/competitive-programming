n = int(input())
a=input();b=input()
print('Deletion', ['failed', 'succeeded'][all(x!=y for x,y in zip(a,b)) if n%2 else a==b])
