for g in open(0).read().split('\n\n'):print(*map(''.join,zip(*sorted(zip(*g.split()))[::-1])),sep='\n'); print()
