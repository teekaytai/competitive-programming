import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = [c for c in input() if c != '.']
    a = []
    i = 0
    while i < len(s):
        if s[i] == 'C':
            if i == len(s) - 1 or s[i + 1] == 'C':
                print('NO'); return
            if len(a) % 2 == 1:
                a.append('.')
            a.extend('CA')
            i += 2
        else:
            j = i + 1
            while j < len(s) and s[j] != s[j - 1]: j += 1
            if (j - i) % 2 == 1:
                a.extend('AC'*((j-i)//2))
                a.append('A')
            else:
                if len(a) % 2 == 1:
                    a.append('.')
                a.extend('AC'*((j-i)//2))
            i = j
    if len(a) > 2*n:
        print('NO')
    else:
        print('YES')
        a.extend('.' * (2*n-len(a)))
        print(''.join(a))

# tcs = int(input())
# for tc in range(tcs):
main()
