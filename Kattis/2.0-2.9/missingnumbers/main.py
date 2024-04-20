_, *a = map(int, open(0))
print(*sorted({*range(1,a[-1])}-{*a}or['good job']),sep='\n')
