_, *a = map(int, open(0))
for x in a:
    mx = 0
    while x:
        mx = max(mx, bin(x).count('1'))
        x //= 10
    print(mx)
