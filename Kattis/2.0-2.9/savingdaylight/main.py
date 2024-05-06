for l in open(0):
    a, s, t = l.rsplit(maxsplit=2)
    h1, m1 = map(int, s.split(':'))
    h2, m2 = map(int, t.split(':'))
    h, m = divmod(60*(h2-h1)+m2-m1, 60)
    print(a, h, 'hours', m, 'minutes')
