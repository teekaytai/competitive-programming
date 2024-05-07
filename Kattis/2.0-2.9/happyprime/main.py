for _ in range(int(input())):
    i, n = map(int, input().split())
    if n==1 or any(n%f==0 for f in range(2, int(n**.5)+1)): print(i, n, 'NO')
    else:
        m = n
        for j in range(100):
            if m == 1: print(i, n, 'YES'); break
            m = sum(int(d)**2 for d in str(m))
        else:
            print(i, n, 'NO')
