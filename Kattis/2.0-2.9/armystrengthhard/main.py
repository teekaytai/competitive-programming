for _ in range(int(input())):
    input()
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()), reverse=True)
    b = sorted(map(int, input().split()), reverse=True)
    while a and b:
        if a[-1] < b[-1]: a.pop()
        else: b.pop()
    print('Godzilla' if a else 'MechaGodzilla')
