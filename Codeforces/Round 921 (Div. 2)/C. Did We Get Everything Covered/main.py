import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n, k, m = map(int, input().split())
    s = input()
    seen = [False] * k
    res = []
    a = k
    b = n
    for c in s:
        o = ord(c) - ord('a')
        if not seen[o]:
            seen[o] = True
            a -= 1
            if a == 0:
                a = k
                seen = [False] * k
                b -= 1
                res.append(c)
                if b == 0:
                    break
    if b == 0:
        print('YES')
    else:
        print('NO')
        res.append(next(chr(ord('a')+i) for i, B in enumerate(seen) if not B))
        res.extend(['a'] * (n - len(res)))
        print(''.join(res))
