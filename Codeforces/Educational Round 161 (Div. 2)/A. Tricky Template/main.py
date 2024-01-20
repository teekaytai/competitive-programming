import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = input()
    b = input()
    c = input()
    CCC = any(z!=y and z!=x for x,y,z in zip(a,b,c))
    print('YES' if CCC else 'NO')
