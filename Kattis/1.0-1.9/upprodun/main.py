n, m = map(int, open(0))
q, r = divmod(m, n)
for _ in range(r): print('*'*(q+1))
for _ in range(n-r): print('*'*q)
