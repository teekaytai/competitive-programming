for l in map(str.strip, open(0)):
    s = ''.join(f'{ord(c):07b}'for c in l)
    print(['free','trapped'][s.count('1')%2|s.count('0')%2])
