while n:=int(input()):
    a = sorted((input() for _ in range(n)), key=lambda s:s[:2])
    print(*a, sep='\n', end='\n\n')
