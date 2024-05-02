for i in range(1, int(input())+1):
    r, p, d = map(int, input().split())
    print('Recipe #', i)
    I = []
    W = 0
    for _ in range(r):
        s, w, x = input().split()
        x = float(x)
        w = float(w)
        if x == 100.0: W = w
        I.append((s, x/100))
    for s, x in I:
        print(s, f'{W*x*d/p:.1f}')
    print('-'*40)
