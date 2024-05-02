d=dict(zip('abcdefghijklmnopqrstuvwxyz ', ['2','22','222','3','33','333','4','44','444','5','55','555','6','66','666','7','77','777','7777','8','88','888','9','99','999','9999','0']))
for i in range(int(input())):
    s = input()
    a = []
    for c in s:
        x = d[c]
        if a and a[-1][0] == x[0]: a.append(' ')
        a.append(x)
    print(f'Case #{i+1}:', ''.join(a))
