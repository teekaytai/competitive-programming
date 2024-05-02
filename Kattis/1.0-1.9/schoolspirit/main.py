n, *a = map(int, open(0))
def g(i):
    k = -1
    return sum(a[j]*.8**(k:=k+1) for j in range(n) if j!=i) / 5
print(g(-1))
print(sum(map(g, range(n)))/n)
