from itertools import chain
n=int(input())
g = [input() for _ in range(n)]
def f(l):
    return l.count('W') == len(l)//2 and 'WWW' not in l and 'BBB' not in l
print(int(all(map(f, chain(g, map(''.join, zip(*g)))))))
