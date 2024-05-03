while n:=int(input()):
    a = [input() for _ in range(n)]
    a.sort(key=lambda d: (d[-4], not d.startswith('12'), int(d[:d.find(':')]), int(d[d.find(':')+1:d.find(':')+3])))
    for d in a: print(d)
    print()
