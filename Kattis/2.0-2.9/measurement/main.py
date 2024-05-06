from itertools import accumulate
v, a, _, b = input().split()
m = [1000, 12, 3, 22, 10, 8, 3]
*p, = accumulate(m, int.__mul__, initial=1)
d = dict(zip('thou inch foot yard chain furlong mile league th in ft yd ch fur mi lea'.split(), p*2))
print(int(v)*d[a]/d[b])
