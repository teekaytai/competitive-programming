MOD = 1000000007
_, *a = map(int, open(0))
for x in a:
    print(8*pow(9,x-1,MOD)%MOD)
