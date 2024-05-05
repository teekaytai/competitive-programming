n, p, k = map(int, input().split())
*T, = [0, *map(int, input().split()), k]
print(sum((t2-t1)*(100+i*p)/100 for i, (t1, t2) in enumerate(zip(T, T[1:]))))
