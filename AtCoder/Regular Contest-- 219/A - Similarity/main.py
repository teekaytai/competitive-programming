import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    ss = [input() for _ in range(n)]
    if m > 15:
        ans = []
        I = list(range(n))
        for i in range(m):
            t = 0
            for j in I:
                t += ss[j][i] == '1'
            if t == len(I) or t == 0:
                ans.append(ss[I[0]][i:])
                break
            elif t * 2 >= len(I):
                ans.append('1')
                I = [j for j in I if ss[j][i] != '1']
            else:
                ans.append('0')
                I = [j for j in I if ss[j][i] != '0']
        else:
            assert False
        print('Yes')
        print(''.join(ans))
    else:
        seen = [False] * (1 << m)
        for s in ss:
            seen[int(s, 2)] = True
        if all(seen):
            print('No')
        else:
            i = seen.index(False)
            print('Yes')
            print(f'{((1 << m) - 1) ^ i:0{m}b}')

main()
