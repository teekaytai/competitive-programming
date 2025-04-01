d = dict(zip('la le lon sha she shon ta te ton'.split(), range(9)))
D = {v: k for k, v in d.items()}
def f(s):
    s = s[:-1]
    x = 0
    while s:
        for k, v in d.items():
            if s.startswith(k):
                s = s[len(k):]
                x = x * 9 + v
                break
    return x

def g(x):
    if not x: return 'las'
    a = ['s']
    while x:
        a.append(D[x % 9])
        x //= 9
    return ''.join(a[::-1])


print(g(sum(map(f, input().split()))))
