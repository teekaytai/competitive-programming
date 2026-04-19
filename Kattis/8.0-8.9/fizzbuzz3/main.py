import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

A = '_in_'
B = 'inals_stands_for_'
C = 'izz_Buzz!'
F = 'F_in_Finals_stands_for_Fizz_Buzz!'
a = len(A)
b = len(B)
c = len(C)
k = a+b+c
L = [a+b+c+3]

ans = []
def main():
    x, y = map(int, input().split())
    x -= 1
    n = 0
    while x >= L[n]:
        n += 1
        if n > y: ans.append('?'); return
        if n >= len(L): L.append(L[-1] * 3 + k)
    for i in range(n, 0, -1):
        if x < L[i-1]: continue
        x -= L[i-1]
        if x < a: ans.append(A[x]); break
        x -= a
        if x < L[i-1]: continue
        x -= L[i-1]
        if x < b: ans.append(B[x]); break
        x -= b
        if x < L[i-1]: continue
        x -= L[i-1]
        ans.append(C[x]); break
    else:
        ans.append(F[x])

tcs = int(input())
for tc in range(tcs):
    main()
print(''.join(ans))
