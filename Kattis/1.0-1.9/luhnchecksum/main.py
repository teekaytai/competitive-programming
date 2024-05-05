_, *a = open(0)
for l in a:
    print(['FAIL','PASS'][sum(sum(map(int, str(int(d)*(1+i%2)))) for i, d in enumerate(l[-2::-1]))%10==0])
