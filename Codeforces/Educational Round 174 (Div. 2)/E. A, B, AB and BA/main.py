import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    A, B, AB, BA = map(int, input().split())
    p = ''
    m = [[], [], [], []]
    l = 0
    for x in s:
        if not p: p = x; l = 1
        elif (p == x) != (l % 2): l += 1
        else: m[2*(p=='B')+l%2].append(l//2); p = x; l = 1
    m[2*(p=='B')+l%2].append(l//2)
    a = 0; b = 0; ab = 0; ba = 0
    for l in m[0]: ab += l
    for l in m[1]: ab += l; a += 1
    for l in m[2]:
        if l > 1: ab += l - 1; a += 1; b += 1
        else: ba += 1
    for l in m[3]: ab += l; b += 1
    # printerr(a, b, ab, ba)
    k = 0
    m[2].sort()
    for l in m[2]:
        if l == 1: k += 1; continue
        if ab <= AB: break
        mn = min(ab - AB, l - 1)
        ab -= mn
        ba += mn
        if mn == l - 1:
            ba += 1; a -= 1; b -= 1
            k += 1
        else:
            m[2][k] -= mn
    for l in m[3]:
        if ab <= AB: break
        mn = min(ab - AB, l)
        ab -= mn
        ba += mn
    for l in m[1]:
        if ab <= AB: break
        mn = min(ab - AB, l)
        ab -= mn
        ba += mn
    m[0].sort(reverse=True)
    for l in m[0]:
        if ab <= AB: break
        mn = min(ab - AB, l)
        ab -= mn
        ba += mn - 1
        a += 1
        b += 1
    # printerr(a, b, ab, ba)
    while k < len(m[2]) and (a > A or b > B):
        l = m[2][k]
        ab -= l - 1
        ba += l
        a -= 1
        b -= 1
        k += 1
    # printerr(a, b, ab, ba)
    d = max(ba - BA, 0)
    ba -= d
    a += d
    b += d
    print(['NO', 'YES'][a<=A and b<=B and ab<=AB and ba<=BA])

tcs = int(input())
for tc in range(tcs):
    main()
