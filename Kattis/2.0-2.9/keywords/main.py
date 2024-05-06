_, *a = open(0)
print(len({w.replace('-',' ').lower() for w in a}))
