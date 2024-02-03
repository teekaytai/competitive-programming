from collections import Counter
*lines, = open(0).read().splitlines()
l = 0
tc = 1
while l < len(lines):
    n = int(lines[l])
    l += 1
    A = []
    B = []
    C = []
    for i in range(n):
        a, b = lines[l + i].split()
        A.append(a)
        B.append(b)
        C.append(Counter(a))
        C[-1].subtract(Counter(b))

    def find_order(comb, sa=[], sb=[]):
        if not comb:
            res = ''.join(sa)
            sa.clear()
            sb.clear()
            return res
        mask = comb
        ia = len(sa)
        ib = len(sb)
        while mask:
            b = mask & -mask
            idx = b.bit_length() - 1
            sa.extend(A[idx])
            sb.extend(B[idx])
            if all(sa[i] == sb[i] for i in range(min(ia, ib), min(len(sa), len(sb)))):
                res = find_order(comb - b)
                if res: return res
            sa[ia:] = []
            sb[ib:] = []
            mask -= b

    best = ''
    for s in range(1, 1 << n):
        totals = Counter()
        mask = s
        while mask:
            b = mask & -mask
            totals.update(C[b.bit_length() - 1])
            mask -= b
        if any(totals.values()): continue
        res = find_order(s)
        if res and (not best or len(res) < len(best) or len(res) == len(best) and res < best):
            best = res

    print(f'Case {tc}:', best or 'IMPOSSIBLE')

    l += n
    tc += 1
