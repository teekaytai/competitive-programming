x, y = input().split()
print([x+'ex', x+'x', x[:-1]+'ex', x][(x[-1]=='e') + 2*(x[-1]in'aiou') + 3*(x.endswith('ex'))]+y)
