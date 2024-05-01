g, s, c = map(int, input().split())
t = 3*g+2*s+c
print('Copper' if t < 2 else ['Estate', 'Duchy', 'Province'][(t>4)+(t>7)] + ' or ' + ['Copper', 'Silver', 'Gold'][(t>2)+(t>5)])
