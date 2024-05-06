d = ['North', 'East', 'South', 'West']
a, b, c = map(d.index, input().split())
print(['No','Yes'][(b-a)%4==2 and (a-c)%4==1 or (b-a)%4==1 and (c-a)%4>1])
