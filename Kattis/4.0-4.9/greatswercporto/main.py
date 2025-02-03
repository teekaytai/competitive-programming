from collections import Counter
from functools import reduce

def main():
    _, *a, x = map(str.strip, open(0))
    letters = list({c for w in (*a, x) for c in w})
    starts = {w[0] for w in (*a, x)}
    def f(num):
        c = Counter()
        p = 1
        for d in reversed(num):
            c[d] += p
            p *= 10
        return c
    vs = reduce(Counter.__iadd__, map(f, a))
    vs.subtract(f(x))

    def dfs(mask, i=0, t=0):
        if i == len(letters):
            return t == 0
        letter = letters[i]
        m = mask
        ans = 0
        while m:
            b = m & -m
            bi = b.bit_length() - 1
            m -= b
            if bi == 0 and letter in starts: continue
            ans += dfs(mask - b, i + 1, t + vs[letter] * bi)
        return ans
    print(dfs(1023))

main()
