import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def p(s):
    return s == s[::-1]

def main():
    s = input()
    n = len(s)
    for i in range(n // 2):
        if s[i] != s[n - i - 1]:
            ans = 0
            a = s[:i] + s[i + 1:]
            if p(a):
                for j in range(i, -1, -1):
                    if s[j] == s[i]: ans += 1
                    else: break
                for j in range(i + 1, n):
                    if s[j] == s[i]: ans += 1
                    else: break
            b = s[:n - i - 1] + s[n - i:]
            if p(b):
                for j in range(n-i-1, -1, -1):
                    if s[j] == s[n-i-1]: ans += 1
                    else: break
                for j in range(n-i, n):
                    if s[j] == s[n-i-1]: ans += 1
                    else: break
            print(ans)
            return
    m = (n + 1) // 2
    a = list(s[:m])
    b = list(s[m:])[::-1]
    ans = 1 if n%2 else 2
    i = len(a) - 1
    while i > 0 and a[i] == b[i - 1]:
        ans += 2
        i -= 1
    print(ans)

# tcs = int(input())
# for tc in range(tcs):
main()
