while True:
    I = input()
    if I == '0': break
    k, m = map(int, I.split())
    c = set(map(int, input().split()))
    x = 1
    for _ in range(m):
        a, b, *C = map(int, input().split())
        x &= len(c&set(C)) >= b
    print(['no','yes'][x])
