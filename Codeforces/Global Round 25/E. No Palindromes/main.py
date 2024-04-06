import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s = input()
    if s != s[::-1]: print('YES\n1\n'+s); return
    if all(c==s[0] for c in s[:len(s)//2]): print('NO'); return
    if all(c == s[0] for c in s[::2]) and all(c == s[1] for c in s[1::2]): print('NO'); return
    i = 0
    while s[i]==s[0]:i+=1
    a = s[i+1:]
    if a != a[::-1]: print('YES\n2\n'+s[:i+1], a)
    else: print('YES\n2\n'+s[:i+2], s[i+2:])


tcs = int(input())
for tc in range(tcs):
    main()
