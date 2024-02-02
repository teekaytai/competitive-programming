n, m, q = map(int, input().split())
E = {(0, *map(int, input().split())) for _ in range(m)}
Q = [(*map(int, input().split()),) for _ in range(q)]
E -= {*Q}
*P, = range(n)
def F(i):
    if P[i] != i: P[i] = F(P[i])
    return P[i]
def U(i, j):
    P[F(i)] = F(j)
for _, u, v in E: U(u, v)
A = []
for t, u, v in Q[::-1]:
    if t: A += ['un' * (F(u) != F(v))]
    else: U(u, v)
for s in A[::-1]: print(s + 'safe')
