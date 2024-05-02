for l in open(0):
    a = l.split()
    s = [x for x in a if x.isalpha()]
    print(sum(float(x) for x in a if x[0].isdigit())/(len(a)-len(s)), ' '.join(s))
