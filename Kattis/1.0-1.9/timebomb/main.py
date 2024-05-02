s='''***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***'''
a = {''.join(s[40*j+4*i:40*j+4*i+3]for j in range(5)):i for i in range(10)}
S = open(0).read()
l = S.find('\n')+1
b = [''.join(S[l*j+4*i:l*j+4*i+3]for j in range(5)) for i in range(l//4)]
x = 0
for d in b:
    i = a.get(d)
    if i is None: print('BOOM!!'); break
    x = 10*x + i
else:
    print('BOOM!!' if x%6 else 'BEER!!')
