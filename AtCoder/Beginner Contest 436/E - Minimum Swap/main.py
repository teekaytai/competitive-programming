import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [x-1 for x in map(int, input().split())]
    done = [a[i] == i for i in range(n)]
    ans = 0
    for i, x in enumerate(a):
        if done[i]: continue
        curr = x
        done[curr] = True
        j = 1
        while curr != i:
            curr = a[curr]
            done[curr] = True
            j += 1
        ans += j * (j - 1) // 2
    print(ans)

main()
