n = int(input())
for i in range(n):
    a = []
    for j in range(20):
        a.append(['aeiou','bcdfg'][j%2][i%5])
        i//=5
    print(''.join(a))
