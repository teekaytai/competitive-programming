_, *a = map(int, open(0))
for x in a:
    print([1,1,2,6,4,0][min(x,5)])
