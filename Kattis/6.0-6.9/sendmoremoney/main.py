from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    s = input()
    letters = sorted(set(s) - {*'+='})
    pi = s.find('+')
    ei = s.find('=')
    starts = {s[0], s[pi + 1], s[ei + 1]}
    def f(num):
        c = Counter()
        p = 1
        for d in reversed(num):
            c[d] += p
            p *= 10
        return c
    vs = f(s[:pi]) + f(s[pi+1:ei])
    vs.subtract(f(s[ei+1:]))

    def dfs(mask, trans=[], i=0, t=0):
        if i == len(letters):
            return t == 0 and s.translate(str.maketrans(''.join(letters), ''.join(map(str, trans))))
        letter = letters[i]
        m = mask
        while m:
            b = m & -m
            bi = b.bit_length() - 1
            m -= b
            if bi == 0 and letter in starts: continue
            trans.append(bi)
            ans = dfs(mask - b, trans, i + 1, t + vs[letter] * bi)
            if ans: return ans
            trans.pop()
    print(dfs(1023) or 'impossible')

main()
