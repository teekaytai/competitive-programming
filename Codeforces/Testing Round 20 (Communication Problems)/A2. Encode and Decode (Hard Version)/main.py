import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    if input() == 'first':
        n = int(input())
        *a, = map(int, input().split())
        ans = []
        for x in a:
            for _ in range(8):
                ans.append(chr(97 + x % 16))
                x >>= 4
        print(''.join(ans))
    else:
        s = input()
        n = len(s) // 8
        print(n)
        ans = []
        for i in range(0, len(s), 8):
            x = 0
            for j in range(i + 7, i - 1, -1):
                x = (x << 4) + ord(s[j]) - 97
            ans.append(x)
        print(*ans)

main()
