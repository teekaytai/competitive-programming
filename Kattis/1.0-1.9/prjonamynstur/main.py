n = int(input().split()[0])
d=dict(zip('.O\\/A^v',[20,10,25,25,35,5,22]))
print(sum(d[c]for _ in range(n)for c in input()))
