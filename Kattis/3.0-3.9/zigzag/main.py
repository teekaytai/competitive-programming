n = int(input())
q, r = divmod(n, 25)
if q == 0: print('a'+chr(97+r))
elif r == 0: print(('az'*q)[:q+1])
else:
    a = [0]
    d = (25 + r + 1) // 2
    a.extend([d, 0])
    for _ in range(q-1): a.append(25-a[-1])
    if r%2==0: a[-1] += -1 if a[-1] > a[-2] else 1
    print(''.join(chr(97+x) for x in a))
