*g,=open(0)
print(sum(l.count('oo.')+l.count('.oo')for l in[*map(''.join,zip(*g))]+g))