import random
for _ in range(1000):
    A = ['A','B','C']
    random.shuffle(A)
    a,b,c = A
    print(a, flush=True)
    x, y = input().split()
    print(x if y=='1' else [b,c][x==b], flush=True)
    input()
