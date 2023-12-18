tcs = int(input())
for tc in range(tcs):
    n = int(input())
    s = input()
    S = sorted(s)
    suf_max = [''] * n
    suf_max[-1] = s[-1]
    for i in range(n - 2, -1, -1):
        suf_max[i] = max(suf_max[i + 1], s[i])
    t = 0
    m = None
    for i, c in enumerate(s):
        if c == suf_max[i]:
            if m is None:
                m = c
            t += c != m
        elif c != S[i]:
            t = -1
            break
    print(t)
