g = [input().split() for _ in range(3)]
def lines():
    for i in range(3):
        yield g[i]
        yield [r[i] for r in g]
    yield [g[i][i] for i in range(3)]
    yield [g[i][2-i] for i in range(3)]
print('Johan' if any(line==['X','X','X']for line in lines()) else 'Abdullah' if any(line==['O','O','O']for line in lines()) else 'ingen','har vunnit')
