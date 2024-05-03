while True:
    n, m = map(int, input().split())
    if not n: break
    mn = float('inf')
    ma, mb = 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        if a > m: continue
        r = b/a
        if r < mn or r == mn and a > ma:
            mn = r
            ma, mb = a, b
    if ma: print(f'Buy {ma} tickets for ${mb}')
    else: print('No suitable tickets offered')
