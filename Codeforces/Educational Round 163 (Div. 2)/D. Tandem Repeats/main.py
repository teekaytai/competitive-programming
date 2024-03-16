import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s = input()
    n = len(s)
    for i in range(n//2, 0, -1):
        A = [s[j] == s[j+i] or s[j] == '?' or s[j+i] == '?' for j in range(n-i)]
        t = sum(A[:i-1])
        lo = 0
        hi = i-1
        while hi < len(A):
            t += A[hi]
            if t == i:
                print(i*2)
                return
            t -= A[lo]
            lo += 1
            hi += 1
    print(0)


tcs = int(input())
for tc in range(tcs):
    main()
