import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    l, n = map(int, input().split())
    o = ord('*')
    a = [0] * l
    b = []
    for _ in range(n):
        v, s = input().split()
        v = int(v)
        b.append((v, [ord(c) - o for c in s]))
    for v, s in b:
        k = next((i for i, c in enumerate(s) if c == 0), default=-1)
        can = True
        if k == -1:
            if len(s) != l - v + 1: break
            for i, c in enumerate(s, start=v-1):
                if 0 != a[i] != c: can = False; break
                a[i] = c
        else:
            if len(s) > l - v + 2: break
            for i in range(k):
                j = v - 1 + i
                if 0 != a[j] != s[i]: can = False; break
                a[j] = s[i]
            for i in range(k + 1, len(s)):
                j = l - len(s) + i
                if 0 != a[j] != s[i]: can = False; break
                a[j] = s[i]
        if not can: break
    else:
        if 0 not in a:
            print(''.join(chr(c + o) for c in a))
            return
    print('IMPOSSIBLE')

tcs = int(input())
for tc in range(tcs):
    main()
